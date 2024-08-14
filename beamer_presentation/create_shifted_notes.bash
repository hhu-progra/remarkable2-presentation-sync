#!/bin/bash

# Input: LaTeX Beamer slides with slides left, notes right
# Output: pdf with notes for current slide and preview of next slide

INPUT="$1"
SLIDES="tmp_slides.pdf"
NOTES="tmp_notes.pdf"
OUTPUT=$(echo $INPUT | sed "s/.pdf/-shifted-notes.pdf/")

PAGE_SIZE=$(pdfinfo "$INPUT" | grep "Page size" | awk '{print $3, $5}')
WIDTH=$(echo $PAGE_SIZE | awk '{print $1}')
HEIGHT=$(echo $PAGE_SIZE | awk '{print $2}')

HALF_WIDTH=$(echo "$WIDTH / 2" | bc)

BBOX="0 0 $HALF_WIDTH $HEIGHT"
pdfcrop --bbox "$BBOX" "$INPUT" "$SLIDES"

BBOX="$HALF_WIDTH 0 $WIDTH $HEIGHT"
pdfcrop --bbox "$BBOX" "$INPUT" "$NOTES"

pdfseparate "$SLIDES" tmp_slide_%04d.pdf &
pdfseparate "$NOTES" tmp_note_%04d.pdf &
wait

NUM_PAGES=$(pdfinfo "$INPUT" | grep Pages | awk '{print $2}')

for ((i=1; i<=NUM_PAGES; i++)); do
    padded_index=$(printf "%04d" $i)
    padded_index_plus_1=$(printf "%04d" $((i + 1)))
    if [[ $i -eq $NUM_PAGES ]]; then
        padded_index_plus_1=$(printf "%04d" 1)
    fi
    pdfjam --nup 1x2 --paper a4paper tmp_slide_${padded_index_plus_1}.pdf tmp_note_${padded_index}.pdf --outfile tmp_combined_${padded_index}.pdf &
    if ((i % 8 == 0)); then
        wait
    fi
done

wait

pdfunite tmp_combined_*.pdf $OUTPUT

echo $OUTPUT written

trash tmp_*.pdf

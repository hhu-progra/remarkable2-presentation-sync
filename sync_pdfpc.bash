#!/bin/bash

# Preferred keyboards in order of priority
# You can get the names from $ xinput list | grep -i 'keyboard'
preferred_keyboards=("Logitech HID compliant keyboard  " "AT Translated Set 2 keyboard  ")

if ! command -v xdotool &> /dev/null; then
    echo "xdotool must be installed"
    exit 1
fi

get_keyboard_id() {
    for keyboard in "${preferred_keyboards[@]}"; do
        keyboard_id=$(xinput list | grep -i "$keyboard" | grep -o 'id=[0-9]*' | grep -o '[0-9]*')
        if [ -n "$keyboard_id" ]; then
            echo using keyboard $keyboard_id
            return $keyboard_id
        fi
    done
    
    keyboard_id=$(xinput list | grep -i 'keyboard' | grep -o 'id=[0-9]*' | grep -o '[0-9]*')
    echo no preferred keyboard found, using $keyboard_id as fallback
    return $keyboard_id
}

get_keyboard_id
keyboard_id=$?

xinput test "$keyboard_id" | while read -r line; do
    if echo "$line" | grep -q "key press"; then
        key_code=$(echo "$line" | awk '{print $3}')

        active_window=$(xdotool getactivewindow getwindowname)

        if [[ $active_window == *"pdfpc"* ]]; then
            if [[ $key_code == 113 ]]; then
                echo "send swipe_right"
                ssh root@10.11.99.1 "/home/root/touch_simulator swipe_right"
            elif [[ $key_code == 114 ]]; then
                echo "send swipe_left"
                ssh root@10.11.99.1 "/home/root/touch_simulator swipe_left"
            fi
        fi
    fi
done

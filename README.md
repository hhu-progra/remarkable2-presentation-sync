# Remarkable 2 as second screen with presentation notes

I wanted to have the following set-up for lectures:

- Laptop screen mirrored with projector
    - mirroring necessary for live programming
    - this screen is always streamed in the lecture live stream
- A second screen where presentation notes are shown
    - We will use the Remarkable 2 for that.

I didn’t want to use a solution which involves VNC since this approach was less reliable in the past (using an Android tablet) and requires a somewhat more complicated set-up.

## Requirements

- ARM cross compiler for C
- X Window System
- Remarkable 2 connected via USB

## Set-up

1. Compile the swipe input simulation software: `arm-linux-gnueabihf-gcc -o touch_simulator touch_simulator.c`
2. Copy the `touch_simulator` to your Remarkable 2 `/home/root` via ssh. (root@10.11.99.1)
    * You should set up an [ssh key](https://remarkable.guide/guide/access/ssh.html#installing-a-ssh-key-on-your-device), otherwise the sync script won’t work.
3. In `sync_presentation.bash`, change the preferred keyboard and presentation software.

## Usage

![](videos/pc.gif =600x)

![](videos/remarkable.gif =300x)

1. Connect the Remarkable with a usb cable.
2. Copy your presentation notes to the Remarkable (e.g. using http://10.11.99.1/) and open them.
2. Start `./sync_presentation.bash`.
3. Now whenever you press left or right arrow while your presentation window has focus, a right/left swipe is simulated on the remarkable.

## LaTeX Beamer Notes and next slide

I wanted to have the next slide and the notes for the current slide on the Remarkable. I use LaTeX beamer for my lectures, so I created a script which takes beamer pdf (with notes) and rearranges its contents to fit my needs. The script and an example presentation are included in the `beamer_presentation` folder.

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <linux/input.h>
#include <string.h>
#include <errno.h>

#define TOUCH_DEVICE "/dev/input/event2"

void print_event(struct input_event *ie) {
    printf("Event type: %d, code: %d, value: %d\n", ie->type, ie->code, ie->value);
}

void record_events(int fd) {
    struct input_event ie;

    while (1) {
        ssize_t bytes_read = read(fd, &ie, sizeof(struct input_event));
        if (bytes_read < 0) {
            perror("read");
            close(fd);
            exit(EXIT_FAILURE);
        }
        if (bytes_read == sizeof(struct input_event)) {
            print_event(&ie);
        }
    }
}

void send_event(int fd, int type, int code, int value) {
    struct input_event ie;

    memset(&ie, 0, sizeof(struct input_event));
    ie.type = type;
    ie.code = code;
    ie.value = value;

    if (write(fd, &ie, sizeof(struct input_event)) < 0) {
        perror("write");
        exit(EXIT_FAILURE);
    }
    usleep(1000); // events may not be sent too fast (probably because of handball detection)
}

// aka next page
void send_swipe_left(int fd) {
    send_event(fd, 3, 57, 437);
    send_event(fd, 3, 53, 1269);
    send_event(fd, 3, 54, 920);
    send_event(fd, 3, 58, 114);
    send_event(fd, 3, 49, 17);
    send_event(fd, 3, 52, 3);
    send_event(fd, 0, 0, 0);
    send_event(fd, 3, 53, 1266);
    send_event(fd, 3, 52, 4);
    send_event(fd, 0, 0, 0);
    send_event(fd, 3, 53, 1262);
    send_event(fd, 3, 58, 115);
    send_event(fd, 3, 52, 3);
    send_event(fd, 0, 0, 0);
    send_event(fd, 3, 53, 1257);
    send_event(fd, 3, 58, 116);
    send_event(fd, 0, 0, 0);
    send_event(fd, 3, 53, 1249);
    send_event(fd, 3, 58, 115);
    send_event(fd, 3, 49, 8);
    send_event(fd, 3, 52, 2);
    send_event(fd, 0, 0, 0);
    send_event(fd, 3, 53, 1239);
    send_event(fd, 3, 58, 111);
    send_event(fd, 3, 49, 17);
    send_event(fd, 3, 52, 4);
    send_event(fd, 0, 0, 0);
    send_event(fd, 3, 53, 1226);
    send_event(fd, 3, 58, 113);
    send_event(fd, 3, 52, 3);
    send_event(fd, 0, 0, 0);
    send_event(fd, 3, 53, 1210);
    send_event(fd, 0, 0, 0);
    send_event(fd, 3, 53, 1193);
    send_event(fd, 3, 54, 921);
    send_event(fd, 3, 58, 118);
    send_event(fd, 0, 0, 0);
    send_event(fd, 3, 53, 1174);
    send_event(fd, 3, 54, 923);
    send_event(fd, 3, 58, 116);
    send_event(fd, 3, 48, 8);
    send_event(fd, 3, 52, 2);
    send_event(fd, 0, 0, 0);
    send_event(fd, 3, 53, 1152);
    send_event(fd, 3, 54, 925);
    send_event(fd, 3, 48, 17);
    send_event(fd, 3, 52, 3);
    send_event(fd, 0, 0, 0);
    send_event(fd, 3, 53, 1128);
    send_event(fd, 3, 54, 927);
    send_event(fd, 3, 58, 114);
    send_event(fd, 3, 48, 8);
    send_event(fd, 3, 52, 2);
    send_event(fd, 0, 0, 0);
    send_event(fd, 3, 53, 1102);
    send_event(fd, 3, 54, 929);
    send_event(fd, 3, 58, 115);
    send_event(fd, 0, 0, 0);
    send_event(fd, 3, 53, 1074);
    send_event(fd, 3, 54, 930);
    send_event(fd, 3, 58, 113);
    send_event(fd, 0, 0, 0);
    send_event(fd, 3, 53, 1040);
    send_event(fd, 3, 54, 931);
    send_event(fd, 3, 58, 110);
    send_event(fd, 0, 0, 0);
    send_event(fd, 3, 53, 1006);
    send_event(fd, 3, 54, 932);
    send_event(fd, 3, 58, 106);
    send_event(fd, 0, 0, 0);
    send_event(fd, 3, 53, 972);
    send_event(fd, 3, 58, 94);
    send_event(fd, 3, 49, 8);
    send_event(fd, 3, 52, 1);
    send_event(fd, 0, 0, 0);
    send_event(fd, 3, 53, 944);
    send_event(fd, 3, 58, 52);
    send_event(fd, 3, 49, 17);
    send_event(fd, 3, 52, 2);
    send_event(fd, 0, 0, 0);
    send_event(fd, 3, 57, -1);
    send_event(fd, 0, 0, 0);
}

// aka previous page
void send_swipe_right(int fd) {
    send_event(fd, 3, 57, 407);
    send_event(fd, 3, 53, 216);
    send_event(fd, 3, 54, 812);
    send_event(fd, 3, 58, 56);
    send_event(fd, 3, 48, 17);
    send_event(fd, 3, 49, 8);
    send_event(fd, 0, 0, 0);
    send_event(fd, 3, 53, 218);
    send_event(fd, 3, 54, 810);
    send_event(fd, 3, 58, 73);
    send_event(fd, 0, 0, 0);
    send_event(fd, 3, 53, 220);
    send_event(fd, 3, 58, 75);
    send_event(fd, 0, 0, 0);
    send_event(fd, 3, 53, 222);
    send_event(fd, 3, 54, 809);
    send_event(fd, 0, 0, 0);
    send_event(fd, 3, 53, 225);
    send_event(fd, 3, 58, 74);
    send_event(fd, 0, 0, 0);
    send_event(fd, 3, 53, 228);
    send_event(fd, 3, 54, 808);
    send_event(fd, 3, 58, 75);
    send_event(fd, 3, 49, 17);
    send_event(fd, 3, 52, 4);
    send_event(fd, 0, 0, 0);
    send_event(fd, 3, 53, 232);
    send_event(fd, 3, 58, 74);
    send_event(fd, 0, 0, 0);
    send_event(fd, 3, 53, 237);
    send_event(fd, 3, 58, 76);
    send_event(fd, 0, 0, 0);
    send_event(fd, 3, 53, 242);
    send_event(fd, 3, 54, 807);
    send_event(fd, 3, 52, 3);
    send_event(fd, 0, 0, 0);
    send_event(fd, 3, 53, 247);
    send_event(fd, 3, 58, 77);
    send_event(fd, 3, 49, 8);
    send_event(fd, 3, 52, 2);
    send_event(fd, 0, 0, 0);
    send_event(fd, 3, 53, 253);
    send_event(fd, 3, 54, 806);
    send_event(fd, 3, 58, 78);
    send_event(fd, 0, 0, 0);
    send_event(fd, 3, 53, 260);
    send_event(fd, 3, 58, 79);
    send_event(fd, 0, 0, 0);
    send_event(fd, 3, 53, 267);
    send_event(fd, 3, 58, 80);
    send_event(fd, 3, 49, 17);
    send_event(fd, 3, 52, 3);
    send_event(fd, 0, 0, 0);
    send_event(fd, 3, 53, 274);
    send_event(fd, 3, 54, 805);
    send_event(fd, 3, 52, 4);
    send_event(fd, 0, 0, 0);
    send_event(fd, 3, 53, 282);
    send_event(fd, 3, 58, 81);
    send_event(fd, 3, 52, 3);
    send_event(fd, 0, 0, 0);
    send_event(fd, 3, 53, 290);
    send_event(fd, 3, 54, 804);
    send_event(fd, 3, 58, 82);
    send_event(fd, 3, 49, 8);
    send_event(fd, 3, 52, 2);
    send_event(fd, 0, 0, 0);
    send_event(fd, 3, 53, 297);
    send_event(fd, 3, 54, 803);
    send_event(fd, 3, 58, 83);
    send_event(fd, 0, 0, 0);
    send_event(fd, 3, 53, 306);
    send_event(fd, 3, 58, 84);
    send_event(fd, 0, 0, 0);
    send_event(fd, 3, 53, 314);
    send_event(fd, 3, 54, 802);
    send_event(fd, 3, 58, 83);
    send_event(fd, 3, 49, 17);
    send_event(fd, 3, 52, 3);
    send_event(fd, 0, 0, 0);
    send_event(fd, 3, 53, 322);
    send_event(fd, 3, 54, 801);
    send_event(fd, 0, 0, 0);
    send_event(fd, 3, 53, 331);
    send_event(fd, 3, 54, 800);
    send_event(fd, 3, 58, 85);
    send_event(fd, 0, 0, 0);
    send_event(fd, 3, 53, 340);
    send_event(fd, 3, 58, 86);
    send_event(fd, 3, 49, 8);
    send_event(fd, 3, 52, 2);
    send_event(fd, 0, 0, 0);
    send_event(fd, 3, 53, 349);
    send_event(fd, 3, 54, 799);
    send_event(fd, 3, 48, 8);
    send_event(fd, 3, 52, 1);
    send_event(fd, 0, 0, 0);
    send_event(fd, 3, 53, 359);
    send_event(fd, 3, 54, 798);
    send_event(fd, 3, 58, 87);
    send_event(fd, 3, 49, 17);
    send_event(fd, 3, 52, 2);
    send_event(fd, 0, 0, 0);
    send_event(fd, 3, 53, 368);
    send_event(fd, 3, 54, 797);
    send_event(fd, 3, 58, 86);
    send_event(fd, 0, 0, 0);
    send_event(fd, 3, 53, 377);
    send_event(fd, 3, 54, 796);
    send_event(fd, 3, 58, 87);
    send_event(fd, 0, 0, 0);
    send_event(fd, 3, 53, 387);
    send_event(fd, 3, 54, 795);
    send_event(fd, 3, 49, 8);
    send_event(fd, 3, 52, 1);
    send_event(fd, 0, 0, 0);
    send_event(fd, 3, 53, 398);
    send_event(fd, 0, 0, 0);
    send_event(fd, 3, 53, 408);
    send_event(fd, 3, 54, 794);
    send_event(fd, 3, 58, 86);
    send_event(fd, 3, 49, 17);
    send_event(fd, 3, 52, 2);
    send_event(fd, 0, 0, 0);
    send_event(fd, 3, 53, 419);
    send_event(fd, 3, 54, 793);
    send_event(fd, 3, 58, 85);
    send_event(fd, 0, 0, 0);
    send_event(fd, 3, 53, 430);
    send_event(fd, 3, 54, 792);
    send_event(fd, 3, 58, 86);
    send_event(fd, 0, 0, 0);
    send_event(fd, 3, 53, 440);
    send_event(fd, 3, 54, 791);
    send_event(fd, 3, 49, 8);
    send_event(fd, 3, 52, 1);
    send_event(fd, 0, 0, 0);
    send_event(fd, 3, 53, 451);
    send_event(fd, 3, 54, 790);
    send_event(fd, 3, 58, 85);
    send_event(fd, 0, 0, 0);
    send_event(fd, 3, 53, 462);
    send_event(fd, 3, 54, 789);
    send_event(fd, 3, 58, 83);
    send_event(fd, 3, 49, 17);
    send_event(fd, 3, 52, 2);
    send_event(fd, 0, 0, 0);
    send_event(fd, 3, 53, 472);
    send_event(fd, 3, 54, 788);
    send_event(fd, 3, 58, 85);
    send_event(fd, 0, 0, 0);
    send_event(fd, 3, 53, 481);
    send_event(fd, 3, 54, 786);
    send_event(fd, 0, 0, 0);
    send_event(fd, 3, 53, 491);
    send_event(fd, 3, 54, 785);
    send_event(fd, 3, 49, 8);
    send_event(fd, 3, 52, 1);
    send_event(fd, 0, 0, 0);
    send_event(fd, 3, 53, 500);
    send_event(fd, 3, 54, 784);
    send_event(fd, 3, 58, 84);
    send_event(fd, 0, 0, 0);
    send_event(fd, 3, 53, 509);
    send_event(fd, 3, 54, 783);
    send_event(fd, 3, 58, 82);
    send_event(fd, 0, 0, 0);
    send_event(fd, 3, 53, 518);
    send_event(fd, 3, 58, 80);
    send_event(fd, 3, 49, 17);
    send_event(fd, 3, 52, 2);
    send_event(fd, 0, 0, 0);
    send_event(fd, 3, 53, 526);
    send_event(fd, 3, 54, 782);
    send_event(fd, 3, 58, 75);
    send_event(fd, 0, 0, 0);
    send_event(fd, 3, 53, 533);
    send_event(fd, 3, 54, 781);
    send_event(fd, 3, 58, 73);
    send_event(fd, 0, 0, 0);
    send_event(fd, 3, 53, 540);
    send_event(fd, 3, 54, 780);
    send_event(fd, 3, 58, 65);
    send_event(fd, 0, 0, 0);
    send_event(fd, 3, 53, 546);
    send_event(fd, 3, 54, 779);
    send_event(fd, 3, 58, 51);
    send_event(fd, 3, 49, 8);
    send_event(fd, 3, 52, 1);
    send_event(fd, 0, 0, 0);
    send_event(fd, 3, 53, 552);
    send_event(fd, 3, 58, 30);
    send_event(fd, 0, 0, 0);
    send_event(fd, 3, 57, -1);
    send_event(fd, 0, 0, 0);
}

// aka next page (landscape)
void send_swipe_down(int fd) {
    send_event(fd, 3, 57, 441);
    send_event(fd, 3, 53, 723);
    send_event(fd, 3, 54, 1775);
    send_event(fd, 3, 58, 81);
    send_event(fd, 3, 49, 8);
    send_event(fd, 3, 52, 2);
    send_event(fd, 0, 0, 0);
    send_event(fd, 3, 54, 1773);
    send_event(fd, 3, 58, 86);
    send_event(fd, 0, 0, 0);
    send_event(fd, 3, 54, 1770);
    send_event(fd, 3, 48, 8);
    send_event(fd, 3, 52, 1);
    send_event(fd, 0, 0, 0);
    send_event(fd, 3, 53, 722);
    send_event(fd, 3, 54, 1764);
    send_event(fd, 3, 49, 17);
    send_event(fd, 3, 52, 2);
    send_event(fd, 0, 0, 0);
    send_event(fd, 3, 53, 720);
    send_event(fd, 3, 54, 1758);
    send_event(fd, 3, 58, 89);
    send_event(fd, 0, 0, 0);
    send_event(fd, 3, 53, 719);
    send_event(fd, 3, 54, 1750);
    send_event(fd, 3, 58, 92);
    send_event(fd, 3, 48, 17);
    send_event(fd, 3, 52, 3);
    send_event(fd, 0, 0, 0);
    send_event(fd, 3, 53, 717);
    send_event(fd, 3, 54, 1741);
    send_event(fd, 0, 0, 0);
    send_event(fd, 3, 53, 714);
    send_event(fd, 3, 54, 1729);
    send_event(fd, 3, 58, 90);
    send_event(fd, 3, 48, 8);
    send_event(fd, 3, 52, 2);
    send_event(fd, 0, 0, 0);
    send_event(fd, 3, 53, 711);
    send_event(fd, 3, 54, 1716);
    send_event(fd, 3, 58, 93);
    send_event(fd, 3, 48, 17);
    send_event(fd, 3, 52, 4);
    send_event(fd, 0, 0, 0);
    send_event(fd, 3, 53, 708);
    send_event(fd, 3, 54, 1701);
    send_event(fd, 3, 58, 91);
    send_event(fd, 3, 48, 8);
    send_event(fd, 3, 52, 2);
    send_event(fd, 0, 0, 0);
    send_event(fd, 3, 53, 704);
    send_event(fd, 3, 54, 1683);
    send_event(fd, 3, 58, 95);
    send_event(fd, 3, 48, 17);
    send_event(fd, 3, 52, 3);
    send_event(fd, 0, 0, 0);
    send_event(fd, 3, 53, 701);
    send_event(fd, 3, 54, 1664);
    send_event(fd, 3, 58, 93);
    send_event(fd, 3, 48, 8);
    send_event(fd, 3, 52, 2);
    send_event(fd, 0, 0, 0);
    send_event(fd, 3, 53, 697);
    send_event(fd, 3, 54, 1643);
    send_event(fd, 3, 58, 94);
    send_event(fd, 3, 48, 17);
    send_event(fd, 3, 49, 8);
    send_event(fd, 0, 0, 0);
    send_event(fd, 3, 53, 693);
    send_event(fd, 3, 54, 1620);
    send_event(fd, 3, 58, 89);
    send_event(fd, 3, 48, 8);
    send_event(fd, 3, 52, 1);
    send_event(fd, 0, 0, 0);
    send_event(fd, 3, 53, 689);
    send_event(fd, 3, 54, 1595);
    send_event(fd, 3, 58, 86);
    send_event(fd, 3, 48, 17);
    send_event(fd, 3, 52, 2);
    send_event(fd, 0, 0, 0);
    send_event(fd, 3, 53, 684);
    send_event(fd, 3, 54, 1567);
    send_event(fd, 3, 58, 77);
    send_event(fd, 3, 48, 8);
    send_event(fd, 3, 52, 1);
    send_event(fd, 0, 0, 0);
    send_event(fd, 3, 53, 679);
    send_event(fd, 3, 54, 1533);
    send_event(fd, 3, 58, 63);
    send_event(fd, 0, 0, 0);
    send_event(fd, 3, 57, -1);
    send_event(fd, 0, 0, 0);
}


// aka previous page (landscape)
void send_swipe_up(int fd) {
    send_event(fd, 3, 57, 442);
    send_event(fd, 3, 53, 718);
    send_event(fd, 3, 54, 217);
    send_event(fd, 3, 58, 82);
    send_event(fd, 0, 0, 0);
    send_event(fd, 3, 54, 220);
    send_event(fd, 3, 58, 89);
    send_event(fd, 3, 49, 17);
    send_event(fd, 3, 52, 2);
    send_event(fd, 0, 0, 0);
    send_event(fd, 3, 54, 227);
    send_event(fd, 3, 58, 96);
    send_event(fd, 3, 48, 17);
    send_event(fd, 3, 52, 3);
    send_event(fd, 0, 0, 0);
    send_event(fd, 3, 53, 717);
    send_event(fd, 3, 54, 238);
    send_event(fd, 3, 58, 93);
    send_event(fd, 3, 48, 8);
    send_event(fd, 3, 52, 2);
    send_event(fd, 0, 0, 0);
    send_event(fd, 3, 53, 716);
    send_event(fd, 3, 54, 254);
    send_event(fd, 3, 58, 102);
    send_event(fd, 3, 48, 17);
    send_event(fd, 3, 52, 3);
    send_event(fd, 0, 0, 0);
    send_event(fd, 3, 53, 715);
    send_event(fd, 3, 54, 280);
    send_event(fd, 3, 58, 103);
    send_event(fd, 0, 0, 0);
    send_event(fd, 3, 53, 713);
    send_event(fd, 3, 54, 329);
    send_event(fd, 3, 58, 100);
    send_event(fd, 3, 48, 8);
    send_event(fd, 3, 52, 2);
    send_event(fd, 0, 0, 0);
    send_event(fd, 3, 53, 712);
    send_event(fd, 3, 54, 399);
    send_event(fd, 3, 58, 104);
    send_event(fd, 3, 48, 17);
    send_event(fd, 3, 52, 3);
    send_event(fd, 0, 0, 0);
    send_event(fd, 3, 53, 713);
    send_event(fd, 3, 54, 468);
    send_event(fd, 3, 58, 91);
    send_event(fd, 3, 48, 8);
    send_event(fd, 3, 52, 2);
    send_event(fd, 0, 0, 0);
    send_event(fd, 3, 53, 719);
    send_event(fd, 3, 54, 536);
    send_event(fd, 3, 58, 47);
    send_event(fd, 3, 49, 8);
    send_event(fd, 3, 52, 1);
    send_event(fd, 0, 0, 0);
    send_event(fd, 3, 57, -1);
    send_event(fd, 0, 0, 0);
}

int main(int argc, char *argv[]) {
    int fd = open(TOUCH_DEVICE, O_RDWR);

    if (fd < 0) {
        perror("open");
        return EXIT_FAILURE;
    }

    if (argc < 2) {
        fprintf(stderr, "Usage: %s (record|swipe_up|swipe_down|swipe_left|swipe_right)\n", argv[0]);
        close(fd);
        return EXIT_FAILURE;
    }
    
    if (strcmp(argv[1], "record") == 0) {
        record_events(fd);
    } else if (strcmp(argv[1], "swipe_up") == 0) {
        send_swipe_up(fd);
    } else if (strcmp(argv[1], "swipe_down") == 0) {
        send_swipe_down(fd);
    } else if (strcmp(argv[1], "swipe_left") == 0) {
        send_swipe_left(fd);
    } else if (strcmp(argv[1], "swipe_right") == 0) {
        send_swipe_right(fd);
    } else {
        fprintf(stderr, "Unknown command: %s, run without arguments for help\n", argv[1]);
        close(fd);
        return EXIT_FAILURE;
    }
    
    close(fd);
    return EXIT_SUCCESS;
}

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>

void pass_auth() {
        if(fork() == 0) {
                char *argv[] = { "sudo", "-v", NULL };
                execvp("sudo", argv);
                perror("execvp");
                _exit(1);
        }
        wait(NULL);
}
void kde() {
        if(fork() == 0) {
                char *argv[] = {"sudo", "pacman", "-S", "--noconfirm", "plasma", NULL};
                execvp("sudo", argv);
                perror("execvp");
                _exit(1);
        }
        wait(NULL);
}
void gnome() {
        if(fork() == 0) {
                char *argv[] = {"sudo", "pacman", "-S" , "--noconfirm", "gnome", NULL};
                execvp("sudo", argv);
                perror("execvp");
                _exit(1);
        }
        wait(NULL);
}
void noctalia() {
        if(fork() == 0) {
                char *argv[] = {"yay", "-S", "--noconfirm", "noctalia", NULL};
                execvp("yay", argv);
                perror("execvp");
                _exit(1);
        }
        wait(NULL);
}
void caelestia() {
        if(fork() == 0) {
                char *argv[] = {"yay", "-S", "--noconfirm", "caelestia-shell", NULL};
                execvp("yay", argv);
                perror("execvp");
                _exit(1);
        }
        wait(NULL);
}
void pkgs() {
        if(fork() == 0) {
                char *argv[] = {"sudo", "pacman", "-S", "--noconfirm", "firefox", "thunar", "kitty", NULL};
                execvp("sudo", argv);
                perror("execvp");
                _exit(1);
        }
        wait(NULL);
}

int main() {
    char HYPRLAND[200];
    char EXTRA_PKGS[300];
    char selection;
    char confirmation;
    char command;

        printf("Authenticate please\n");
        pass_auth();

    printf("\nChoose your Desktop environment first\n");
    printf("1. KDE-plasma\n");
    printf("2. GNOME\n");
    printf("3. Niri (Note: this is window manager rather than a traditional desktop environment, but ill manage it for you :3 )\n");
    printf("4. Hyprland (Note: this is a window manager rather than a traditional desktop environment, but ill manage it for you :3)\n");
    printf("choose a number please:- ");

    scanf(" %c", &selection);

    switch (selection) {
        case '1':
            kde();
            break;
        case '2':
            gnome();
            break;
        case '3':
            printf("installing niri......\n");
            if(fork() == 0) {
                        char *argv[] = { "sudo", "pacman", "-S", "--noconfirm", "niri", NULL };
                        execvp("sudo", argv);
                        perror("execvp");
                        _exit(1);
            }
            wait(NULL);

            printf("\nChoose your shell!\n");
            printf("1. Noctalia\n");
            printf("2. Caelestia\n");
            printf("Type your number!:- ");
            scanf(" %c", &confirmation);

            switch (confirmation) {
                case '1':
                    noctalia();
                    chdir("niri");
                    system("echo 'spawn-sh-at-startup \"qs -c noctalia-shell\"' >> config.kdl");
                    printf("\nAdded Noctalia to autostart!\n");
                    break;
                case '2':
                    caelestia();
                    chdir("niri");
                    system("echo 'spawn-sh-at-startup \"caelestia shell\"' >> config.kdl");
                    printf("\nAdded caelestia shell to autostart!\n");
                    break;
            }
            break;
        case '4':
            printf("installing hyprland....\n");
            if(fork() == 0) {
                        char *argv[] = { "sudo", "pacman", "-S", "--noconfirm", "hyprland", NULL };
                        execvp("sudo", argv);
                        perror("execvp");
                        _exit(1);
          }
          wait(NULL);

            printf("\nChoose your shell\n");
            printf("1. Noctalia\n");
            printf("2. Caelestia\n");
            printf("Type your number!:- ");
            scanf(" %c", &confirmation);

            switch (confirmation) {
                case '1':
                    noctalia();
                    chdir("hypr");
                    system("echo '\nhl.on(\"hyprland.start\", function() hl.exec_cmd(\"qs -c noctalia-shell\") end)' >> hyprland.lua");
                    printf("\nAdded Noctalia to autostart!\n");
                    break;
                case '2':
                    caelestia();
                    chdir("hypr");
                    system("echo '\nhl.on(\"hyprland.start\", function() hl.exec_cmd(\"caelestia shell\") end)' >> hyprland.lua");
                    printf("\nAdded Caelestia to autostart!\n");
                    break;
            }
            break;
    }

    printf("\nadding additional packages including firefox, Dolphin, and kitty\n");
    printf("want to add?:\n");
    printf("1. yes\n");
    printf("2. no\n");
    printf("choose a number please:- ");
    scanf(" %c", &command);

    switch (command) {
        case '1':
            pkgs();
            break;
        case '2':
            break;
    }

    printf("\nDone!\n");
    return 0;
}

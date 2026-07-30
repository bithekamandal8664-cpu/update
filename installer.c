#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int main() {
	char password[100];
	char KDE[100];
	char GNOME[100];
	char NIRI[100];
	char HYPRLAND[100];
	char selection[10];
	char confirmation[10];
	char command[10];

	printf("type your password first");
	fgets(password, sizeof(password), stdin);
	password[strcspn(selection, "\n")] = '\0';
	
	printf("\nChoose your Desktop environment first\n");
	printf("1. KDE-plasma\n");
	printf("2. GNOME\n");
	printf("3. Niri (Note: this is window manager rather than a traditional desktop environment, but ill manage it for you :3 )\n");
	printf("4. Hyprlad (Note; this is a window manager rather than a traditional desktop enviroment, but ill manage it for you :3)\n");
	printf("choose a number please:- ");
	scanf("%s", selection);

	snprintf(KDE, sizeof(KDE), "echo '%s' | sudo -S pacman -S plasma", password);
	snprintf(GNOME, sizeof(GNOME), "echo '%s' | sudo -S pacman -S gnome", password);
	snprintf(NIRI, sizeof(NIRI), "echo '%s' | sudo -S pacman -S niri", password);
	snprintf(HYPRLAND, sizeof(HYPRLAND), "echo '%s' | sudo -S pacman -S hyprland", password);

	switch (selection) {
		case 1:
			system(KDE);
			break;
		case 2:
			system(GNOME);
			break;
		case 3:
			printf("installing niri......\n");
			system(NIRI);

			printf("\nChoose your shell!\n");
			printf("1. Noctalia\n");
			printf("2. Caelestia\n");
			printf("Type your number!:- ");
			scanf("%s", confirmation);

			switch (confirmation) {
				case 1:
					system("yay -S Noctalia");
					system("echo 'spawn-sh-at-startup \"qs -c noctalia-shell\"' >> ~/.config/niri/cfg/autostart.kdl");
					printf("\nAdded Noctalia to autostart!\n");
					break;
				case 2:
					system("yay -S caelestia-shell");
					system("echo 'spawn-sh-at-startup \"qs -c noctalia-shell\"' >> ~/.config/niri/cfg/autostart.kdl");
					printf("\nAdded caelestia shell to autostart!\n");
					break;
			}
			break;	
		case 4:
			printf("installing hyprland....\n");
			system(HYPRLAND);

			printf("\nChoose your shell\n");
			printf("1. Noctalia\n");
			printf("2. Caelestia\n");
			printf("Type your number!:- ");
			scanf("%s", confirmation);

			switch (confirmation) {
				case 1:
					system("yay -S Noctalia");
					system("echo '\nhl.on(\"hyprland.start\", function() hl.exec_cmd(\"qs -c noctalia-shell\") end)' >> ~/.config/hypr/hyprland.lua");
					printf("\nAdded Noctalia to autostart!\n");
					break;
				case 2:
					system("yay -S caelestia-shell");
					system("echo '\nhl.on(\"hyprland.start\", function() hl.exec_cmd(\"caelestia shell\") end)' >> ~/.config/hypr/hyprland.lua");
					printf("\nAdded Caelestia to autostart!");
					break;
			}
			break;
	}
	printf("adding additional packages including firefox, Dolphin, and kitty\n");
	printf("want to add?:\n");
	printf("1. yes\n");
	printf("2. no\n");
	scanf("%s", command);

	switch (command) {
		case 1:
			system("echo '%s' | sudo -S pacman -S --noconfirm firefox dolphin kitty");
			break;
		case 2:
			break;
	}
	return 0;
}





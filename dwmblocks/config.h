//Modify this file to change what commands output to your statusbar, and recompile using the make command.

static const Block blocks[] = {
	/*Icon*/	/*Command*/		/*Update Interval*/	/*Update Signal*/
	{"🔊", "pamixer --get-volume-human",				5,			10},

	//KEYBOARD
	{"🎹", "xkblayout-state print '%n'",	1,		0},

	//RAM

	{"💾", "free -h | awk '/^Mem/ { print $3\"/\"$2 }' | sed s/i//g",	10,		0},

	//CPUTEMP
	{"🌡", "cputemp",	5,			0},

	//GPUTEMP
	{"🌡", "gputemp",	5,			0},

	//DISK
	{"📁/", "df -h / | grep / | awk '{print $4}'",	10,		0},

	{"📁~", "df -h /home/ | grep / | awk '{print $4}'",	10,		0},

	//BATTERY
	//{"", "cat /etc/status/pipes/battery | cut -d ' ' -f 3",	10,		0},

	//DATE
	{"📅", "date '+%Y-%m-%d(%a)'",					5,			0},

	//TIME
	{"⌚", "date '+%I:%M:%S%p'",					1,			0},
};
//Sets delimiter between status commands. NULL character ('\0') means no delimiter.
static char *delim = " ";

// Have dwmblocks automatically recompile and run when you edit this file in
// vim with the following line in your vimrc/init.vim:

// autocmd BufWritePost ~/.local/src/dwmblocks/config.h !cd ~/.local/src/dwmblocks/; sudo make install && { killall -q dwmblocks;setsid dwmblocks & }

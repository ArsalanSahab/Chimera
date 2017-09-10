// Include your STL headers here
#include <iostream>
#include <string>
#include <cctype>
#include <vector>
#include <algorithm>
#include <unistd.h>
#include <sys/file.h>
#include <sys/stat.h>
#include <string.h>
#include <stdio.h>
#include <dirent.h>
#include <stdlib.h>
#include <sys/types.h> 
#include <fcntl.h> 
#include <sys/ioctl.h>
#include <pwd.h>
#include <grp.h>
#include <utility>
#include <map>

using namespace std;

// Include your header file below here
#include "split_command_and_flags.h"
#include "pwd.h"
#include "exit_command.h"
#include "make_dir.h"
#include "cd.h"
#include "removedir.h"
#include "ls.h"

int main() {

	struct passwd *pwd;
	pwd_a = getpwuid(fileStat.st_uid);
	string root_name = pwd_a->pw_name;
	while (1) {
		string command;
		cout << root_name << "@ubuntu:";
		getline(cin, command);
		vector < string > commands = split(command, ' ');
		if (commands[0] == "pwd") {
			pwd();
		}
		else if (commands[0] == "mkdir") {
			make_dir();
		}
		else if (commands[0] == "cd") {
			cd();
		}
		else if (commands[0] == "ls") {
			ls();
		}
		else if (commands[0] == "rmdir") {
			remdir();
		}
		else if(commands[0] == "exit") {
			exit_command();
		}
		else {
			cout << "Invalid command" << endl;
		}
	}
	return 0;
}

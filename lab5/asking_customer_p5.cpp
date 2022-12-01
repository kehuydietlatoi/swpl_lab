//
// Created by hung on 01.12.22.
//
#include <bits/stdc++.h>
#include <iostream>
#include <sys/stat.h>
#include <sys/types.h>
using namespace std;

int main() {

  std::cout << "Hallihallo, customer. I'm the smartest AI alive :)"<< std::endl;
  std::cout << "Welcome to automatic configuration program :) Pls answer the questions" << std::endl;
  std::cout << "What is new radio name ?." << std::endl;
  string name;
  std::cin >> name;
  std::string language;
  do {
    std::cout << "Which language do you wanna have ? Type german or english and press enter. If ur input is invalid, u have to answer again." << std::endl;
    std::cin >> language;
  } while (language != "german" and language != "english");

  std::cout << "Which kind off arrow do you wanna have ? Type 1 for single or 2 for double . (Wrong input will be automatically set to 2)" << std::endl;
  int arrow;
  std::cin >> arrow;

  std::cout << "Do u wanna have manuel tuning ? Type 1 if yes or 0 if no .(Wrong input will be automatically set to yes)" << std::endl;
  bool manuel_tuning;
  std::cin >> manuel_tuning;
  bool fast_auto_tuning = false;
  if (manuel_tuning) {
    std::cout << "Do u wanna have fast auto tuning ? Type 1 if yes or 0 if no .(Wrong input will be automatically set to yes)" << std::endl;

    std::cin >> fast_auto_tuning;
  }

  std::cout << "Do u wanna have auto tuning ? Type 1 if yes or 0 if no .(Wrong input will be automatically set to yes)" << std::endl;
  bool auto_tuning;
  std::cin >> auto_tuning;
  bool fast_freq_tuning = false;
  if (auto_tuning){
    std::cout << "Do u wanna have fast freq tuning ? Type 1 if yes or 0 if no .(Wrong input will be automatically set to 0)" << std::endl;
    std::cin >> fast_freq_tuning;
  }

  std::cout << "Do u wanna have numeric keypad? Type 1 if yes or 0 if no .(Wrong input will be automatically set to 0)" << std::endl;
  bool numeric_keypad;
  std::cin >> numeric_keypad;
  std::cout << "Done..... Processing config." << std::endl;
  //---------------------------------------
  // Creating a directory
  const char* tmp = name.c_str();
  if (mkdir(tmp, 0777) == -1)
    cerr << "Error :  " << strerror(errno) << endl;
  else {
    cout << "Directory created";
  }

  //---------------------------------------
  // Create and open a text file
  ofstream basicOption(name+"/option.txt");

  // Write to the file
  basicOption << "#define UP &uarr;" << std::endl;
  basicOption << "#define DOWN &darr;" << std::endl;
  cout << arrow << endl;
  if ( arrow == 2 ){
    basicOption << "#define LEFT &lt;&lt;" << std::endl;
    basicOption << "#define RIGHT &gt;&gt;" << std::endl;
  } else{
    basicOption << "#define LEFT &larr;" << std::endl;
    basicOption << "#define RIGHT &rarr;" << std::endl;
  }

  basicOption << "#define LANGUAGE "<<language << std::endl;
  if (manuel_tuning){
    basicOption << "#define MANUEL_TUNING_FEATURE 1" << std::endl;
  }
  if (auto_tuning){
    basicOption << "#define AUTO_TUNING_FEATURE 1" << std::endl;
  }
  if (fast_auto_tuning){
    basicOption << "#define FAST_AUTOMATIC_TUNING_FEATURE 1" << std::endl;
  }
  if (fast_freq_tuning){
    basicOption << "#define FAST_FREQUENCY_TUNING_FEATURE 1" << std::endl;
  }
  if (numeric_keypad){
    basicOption << "#define NUMERIC_KEYPAD_TUNING_FEATURE 1" << std::endl;
  }
  // command to run
  basicOption << "//";
  //  gcc -E -P -Wall -D DARMSTADT -o DarmstadtNew.html solution.cpp
  basicOption << "gcc -E -P -Wall -D NAME="<< name << " -o output.html p3.cpp";
  basicOption.close();
  //std::ofstream { "Hello.txt" };
  return 0;
}

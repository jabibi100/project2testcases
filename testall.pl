#!/usr/bin/perl

use warnings;
use strict;
use Term::ANSIColor;
use File::Compare;

# root dir of all tests
my $root = '.';
my $compiler = '../cc1';

#counters
my $testPass = 0;
my $totalTest = 0;

#diff command
my $command = "sdiff";


#Open root dir
opendir(D, $root) || die "Can't open directory: $!\n";

while (my $f = readdir(D)) {
    if ( -d $f ){
		if ( $f ne "." && $f ne ".."){
			# For each directory iterate through all test cases and compare output storing results
			opendir(TESTDIR, "$root/$f");
			
			#print title report 
			print colored( "**********************************************************************************", 'BLACK ON_WHITE' ), "\r\n";
			print colored( "**********                                                              **********", 'BLACK ON_WHITE' ), "\r\n";
			print colored( sprintf("**************** Running %-40s ****************", "$f Tests"), 'BLACK ON_WHITE' ), "\n";
			print colored( "**********                                                              **********", 'BLACK ON_WHITE' ), "\r\n";
			print colored( "**********************************************************************************", 'BLACK ON_WHITE' ), "\r\n";
			
			#clean up assembly files
			`rm -f $root/$f/*.s`;
					
			#iterate through each test file
			while (my $testfile = readdir(TESTDIR)){
				if (!-d $testfile && $testfile ne "answers"){		# hack to ignore answer folder cause somehow the -d is not working right....
										
					#run each test case
					`$compiler "$f/$testfile" 2>/dev/null`;
					
					#clean up assembly files
					`rm -f $root/$f/*.s`;
					if($? != 0){
						print colored( sprintf("%-40sCRASH FAIL", $testfile), 'BLACK ON_RED' ), "\n";
					}
					else{
						my $answerFileName = substr($testfile, 0, -2) . ".txt";
						my $diffResults = `$command ./output.txt ./$f/answers/$answerFileName -s -W`;
						
						if($? != 0){
							print colored( sprintf("%-40sFAIL", $testfile), 'red' ), "\n";
						}
						elsif (length($diffResults) != 0) {
							print colored( sprintf("%-40s", $testfile), 'bright_blue' );
							print colored("FAIL", "red"), "\n";
						}
						else{
							print colored( sprintf("%-40s", $testfile), 'bright_blue' );
							print colored("PASS", "green"), "\n";
							$testPass++;
						}
					}
					$totalTest++;
				}
			}

			print "\n\n";
			closedir(TESTDIR);			
		}
	}
}
closedir(D);

#print final test results
if($totalTest == $testPass){
	print colored('  /$$$$$$  /$$   /$$  /$$$$$$   /$$$$$$  /$$$$$$$$  /$$$$$$  /$$', 'green'), "\n";
	print colored(' /$$__  $$| $$  | $$ /$$__  $$ /$$__  $$| $$_____/ /$$__  $$| $$', 'green'), "\n";
	print colored('| $$  \__/| $$  | $$| $$  \__/| $$  \__/| $$      | $$  \__/| $$', 'green'), "\n";
	print colored('|  $$$$$$ | $$  | $$| $$      | $$      | $$$$$   |  $$$$$$ | $$', 'green'), "\n";
	print colored(' \____  $$| $$  | $$| $$      | $$      | $$__/    \____  $$|__/', 'green'), "\n";
	print colored(' /$$  \ $$| $$  | $$| $$    $$| $$    $$| $$       /$$  \ $$    ', 'green'), "\n";
	print colored('|  $$$$$$/|  $$$$$$/|  $$$$$$/|  $$$$$$/| $$$$$$$$|  $$$$$$/ /$$', 'green'), "\n";
	print colored(' \______/  \______/  \______/  \______/ |________/ \______/ |__/', 'green'), "\n\n";
	
	print colored("Passed: $testPass / $totalTest", 'green') , "\n\n\n";
}
else{
	print colored('             (             (              (    (         (      ', 'YELLOW'), "\n";
	print colored('  *   )      )\ )  *   )   )\ )    (      )\ ) )\ )      )\ )   ', 'YELLOW'), "\n";
	print colored('` )  /( (   (()/(` )  /(  (()/(    )\    (()/((()/(  (  (()/(   ', 'YELLOW'), "\n";
	print colored(' ( )(_)))\   /(_))( )(_))  /(_))((((_)(   /(_))/(_)) )\  /(_))  ', 'YELLOW'), "\n";
	print colored('(_(_())((_) (_)) (_(_())  (_))_| )\ _ )\ (_)) (_))  ((_)(_))_   ', 'YELLOW'), "\n";
	print colored('|_   _|| __|/ __||_   _|  | |_   (_)_\(_)|_ _|| |   | __||   \  ', 'red'), "\n";
	print colored('  | |  | _| \__ \  | |    | __|   / _ \   | | | |__ | _| | |) | ', 'red'), "\n";
	print colored('  |_|  |___||___/  |_|    |_|    /_/ \_\ |___||____||___||___/  ', 'red'), "\n\n";
	
	print colored("Passed: $testPass / $totalTest", 'red') , "\n\n\n";
	
}


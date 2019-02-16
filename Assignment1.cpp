
* Katherine Hansen
* 2326665
* kahansen@chapman.edu
* CPSC250-01
* Assignment 1
* This program displays statistical information about DNA strings read from a file and creates new DNA strings based on the statistcs of the orignal set
*/
#include <iostream>
#include <fstream>
#include <string>
#include <math.h>
#include <cstdlib>

using namespace std;

//declaring all methods that will be used in this program
int sum(string sequence);
double mean(string sequence);
double variance(string sequence);
double standardDev(string sequence);
double probability(string sequence, string letter);
double nucleoProb(string sequence, double numPair, string pair);
double numPairs(string sequence);
string generator(double standDev, double means, double probA, double probC, double probT, double probG);

int main(int argc, char** argv){
	bool repeat=true; //a boolean to check if the user wants to repeat later
	//creating .out file
	string fileName = argv[1];
	ofstream out;
	out.open("KatherineHansen.out");
	out << "Katherine Hansen\n";
	out << "2326665\n";
	out << "kahansen@chapman.edu\n";
	out << "CPSC350-01\n";
	out << "Assignment 1\n\n";
	
	while(repeat){
		std::string name = fileName;
		std::ifstream infile(name.c_str());
		string sequence="";
		if(infile.fail()){
			cout << "Your file didn't work" << endl;
		}
		//reading each line from the file
		else{
			string line;
			while(infile>>line){
				sequence+=line+" ";
			}
		}
		//}
		//ensuring all nucleotides are capitalized
	
		int length=sequence.size();
		string sequenceDouble= sequence;
		sequence ="";
		for(int i=0; i<sequenceDouble.length(); i++){
			char seq = sequenceDouble.at(i);
			sequence+=toupper(seq);
		}
		//caculating various information about the DNA sequences
		int sums =sum(sequence);
		double means = mean(sequence);
		double variances = variance(sequence);
		double standDev = standardDev(sequence);
	
		//outputting sum to out file
		out << "Sum: ";
		out << sums;
		out << "\n";
		
		//outputting mean to out file
		out << "Mean: ";
		out << means;
		out << "\n";
	
		//outputting variance to out file
		out << "Variance: ";
		out << variances;
		out << "\n";
	
		//outputting standard deviation to out file
		out << "Standard deviation: ";
		out << standDev;
		out << "\n";
	
		//Checking probability of each individual letter
		string letter="A";
		double probA =probability(sequence, letter)*100;
		out << "Probability of A: ";
		out << probA;
		out << "% \n";
	
		letter="C";
		double probC =probability(sequence, letter)*100;
		out << "Probability of C: ";
		out << probC;
		out << "% \n";
	
		letter="T";
		double probT =probability(sequence, letter)*100;
		out << "Probability of T: ";
		out << probT;
		out << "% \n";
	
		letter="G";
		double probG =probability(sequence, letter)*100;
		out << "Probability of G: ";
		out << probG;
		out << "% \n";
	
		//Checking probability of nucleotide bigrams and outputting to out file
		double num= numPairs(sequence);
		double prob = nucleoProb(sequence, num, "AA")*100;
		out << "Probability of AA: ";
		out << prob;
		out << "% \n";
	
		prob = nucleoProb(sequence, num, "AC")*100;
		out << "Probability of AC: ";
		out << prob;
		out << "% \n";
	
		prob = nucleoProb(sequence, num, "AT")*100;
		out << "Probability of AT: ";
		out << prob;
		out << "% \n";	
	
		prob = nucleoProb(sequence, num, "AG")*100;
		out << "Probability of AG: ";
		out << prob;
		out << "% \n";
	
		prob = nucleoProb(sequence, num, "CA")*100;
		out << "Probability of CA: ";
		out << prob;
		out << "% \n";
	
		prob = nucleoProb(sequence, num, "CC")*100;
		out << "Probability of CC: ";
		out << prob;
		out << "% \n";
	
		prob = nucleoProb(sequence, num, "CT")*100;
		out << "Probability of CT: ";
		out << prob;
		out << "% \n";	
	
		prob = nucleoProb(sequence, num, "CG")*100;
		out << "Probability of CG: ";
		out << prob;
		out << "% \n";
	
		prob = nucleoProb(sequence, num, "TA")*100;
		out << "Probability of TA: ";
		out << prob;
		out << "% \n";
	
		prob = nucleoProb(sequence, num, "TC")*100;
		out << "Probability of TC: ";
		out << prob;
		out << "% \n";
	
		prob = nucleoProb(sequence, num, "TT")*100;
		out << "Probability of TT: ";
		out << prob;
		out << "% \n";	
	
		prob = nucleoProb(sequence, num, "TG")*100;
		out << "Probability of TG: ";
		out << prob;
		out << "% \n";
	
		prob = nucleoProb(sequence, num, "GA")*100;
		out << "Probability of GA: ";
		out << prob;
		out << "% \n";
		
		prob = nucleoProb(sequence, num, "GC")*100;
		out << "Probability of GC: ";
		out << prob;
		out << "% \n";
	
		prob = nucleoProb(sequence, num, "GT")*100;
		out << "Probability of GT: ";
		out << prob;
		out << "% \n";	
	
		prob = nucleoProb(sequence, num, "GG")*100;
		out << "Probability of GG: ";
		out << prob;
		out << "% \n";
		
		//creating the random DNA strings and sending it to out file
		string randDNA=generator(standDev, means, probA, probC, probT, probG);
		out << randDNA;


		cout << "Would you like to process another list? Y/N" << endl;
		string again;
		cin >> again;
		if(again.compare("Y")==0){
			repeat=true;
			cout << "What file would you like to process?" << endl;
			cin >> fileName;
		}
		else{
			repeat=false;
			cout << "Thank you!" << endl;
		}
	}
	return 0;
}
//this method calculates the sum of the number of nucleotides in all of the DNA strings
int sum(string sequence) {
	int count=0;
	for(int i=0; i<sequence.length(); i++){
		if(sequence.substr(i,1).compare("A")==0||sequence.substr(i,1).compare("C")==0||sequence.substr(i,1).compare("T")==0||sequence.substr(i,1).compare("G")==0){
			count++;
		}
	}
	return count;
}
//this method calculates the mean length of all of the DNA strings
double mean(string sequence){
	int sums = sum(sequence);
	double count=0.0;
	for(int i=0; i<sequence.length(); i++){
		if(sequence.substr(i,1).compare(" ")==0){
			count++;
		}
	}
	double mean = sums/count;
	return mean;
}
//This method calculates the variance for the DNA strings
double variance(string sequence){
	double var=0;
	int length=0;
	int numCount=0;
	double means= mean(sequence);
	for(int i=0; i<sequence.length();i++){
		if(sequence.substr(i,1).compare("A")==0||sequence.substr(i,1).compare("C")==0||sequence.substr(i,1).compare("T")==0||sequence.substr(i,1).compare("G")==0){
			length++;
		}
		else if(sequence.substr(i,1).compare(" ")==0){
			numCount++;
			var+=(length-means)*(length-means);
			length=0;
		}
	}
	return var/(numCount-1);
}
//This method calculates the standard deviation for the DNA strings
double standardDev(string sequence){
	return sqrt(variance(sequence));
}
//This method calculates the probability of a given nucleotide
double probability(string sequence, string letter){
	int total = sum(sequence);
	double let=0;
	for(int i=0; i<sequence.length();i++){
		if(sequence.substr(i,1).compare(letter)==0)
			let++;
	}
	
	return let/total;
	
}
//This method calculates the number of nucleutide bigrams in the file
double numPairs(string sequence){
	int count=0;
	for(int i=0; i<sequence.length();i+=2){
		if(sequence.substr(i,1).compare(" ")==0){
			i++;
		}
		else{
			count++;
		}
	}
	return count;

}
//this method calculates the probability of a given nucleutide bigram
double nucleoProb(string sequence, double numPair, string pair){
	int count=0;
	for(int i=0; i<sequence.length();i+=2){
		if(sequence.substr(i,1).compare(" ")==0){
			i--;
		}
		else if(sequence.substr(i,2).compare(pair)==0){
			count++;
		}
	}
	return count/numPair;
}
//This method generates random DNA strings based on the gaussian distribution of the original strings
string generator(double standDev, double mean, double probA, double probC, double probT, double probG){
	//Generating two random numbers
	double a = ((double) rand() /(RAND_MAX));
	double b =((double) rand() /(RAND_MAX));
	
	//Hint from Professor German
	double C = (sqrt(-2*log(a)))*(cos(2*(M_PI)*b));
	double D = standDev *C + mean+1;
	string randDNA="";
	if(D<0)
		D*=-1;
	int count=0;
	while(count<1000){
		for(int i = 0; i < D; ++i) {
			double size = rand() % 100; //generating a random number lower than 100 
			//This gives ranges of how often each nucleotide should be used, generating them at the same rate they appear in the original
			if(size <= probA) {
				randDNA+= "A";
			}
			else if(size <= (probA + probC)) {
				randDNA+= "C";
			}
			else if(size <= (probA + probC + probT)) {
				randDNA+= "T";
			}
			else {
				randDNA+= "G";
			}
		}
		randDNA+="\n";
		count++;
	}
	return randDNA;
}

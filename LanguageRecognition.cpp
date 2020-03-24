#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

class LanguageRecognition {
	public:

	int whichLanguage(vector <string> languages, string text) {
		int lanc=languages.size();
		double lanfreq[lanc][26];
		for(int i=0;i<lanc;i++){
			for(int j=0;j<26;j++){
				lanfreq[i][j]=0;
			}
		}



		for(int i=0;i<lanc;i++){
			int lettercount=0;
			for(int j=0;j<languages[i].size();j++){
				char c = languages[i][j];
				if((c>='a'&&c<='z') || (c>='A'&&c<='Z')){
					lettercount++;
				}
			}

			for(int j=0;j<languages[i].size();j++){
				char c = languages[i][j];
				if(c>='A' && c<='Z'){
					c+='a';
					c-='A';
				}

				if(c>='a' && c<='z'){
					lanfreq[i][c-'a']+=(1.0/lettercount);
				}
			}
		}

		double textfreq[26];
		for(int i=0;i<26;i++){
			textfreq[i]=0;
		}

		int textlettercount=0;

		for(int i=0;i<text.size();i++){
			char c = text[i];
			if((c>='a'&&c<='z') || (c>='A'&&c<='Z')){
				textlettercount++;
			}
		}


		for(int i=0;i<text.size();i++){
			char c = text[i];
			if(c>='A' && c<='Z'){
				c+='a';
				c-='A';
			}

			if(c>='a' && c<='z'){
				textfreq[c-'a']+=(1.0/textlettercount);
			}
		}

		double score[lanc];

		for(int i=0;i<lanc;i++){
			score[i]=0;
		}

		for(int i=0;i<lanc;i++){
			for(int j=0;j<26;j++){
				double temp=lanfreq[i][j]-textfreq[j];
				score[i]+=temp*temp;
			}
		}

		double minscore=score[0];
		int minind=0;

		for(int i=0;i<lanc;i++){
			if(score[i]<minscore){
				minscore=score[i];
				minind=i;
			}
		}
		return minind;
	}
};

// BEGIN CUT HERE
#include <cstdio>
#include <ctime>
#include <iostream>
#include <string>
#include <vector>
namespace moj_harness {
	using std::string;
	using std::vector;
	int run_test_case(int);
	void run_test(int casenum = -1, bool quiet = false) {
		if (casenum != -1) {
			if (run_test_case(casenum) == -1 && !quiet) {
				std::cerr << "Illegal input! Test case " << casenum << " does not exist." << std::endl;
			}
			return;
		}
		
		int correct = 0, total = 0;
		for (int i=0;; ++i) {
			int x = run_test_case(i);
			if (x == -1) {
				if (i >= 100) break;
				continue;
			}
			correct += x;
			++total;
		}
		
		if (total == 0) {
			std::cerr << "No test cases run." << std::endl;
		} else if (correct < total) {
			std::cerr << "Some cases FAILED (passed " << correct << " of " << total << ")." << std::endl;
		} else {
			std::cerr << "All " << total << " tests passed!" << std::endl;
		}
	}
	
	int verify_case(int casenum, const int &expected, const int &received, std::clock_t elapsed) { 
		std::cerr << "Example " << casenum << "... "; 
		
		string verdict;
		vector<string> info;
		char buf[100];
		
		if (elapsed > CLOCKS_PER_SEC / 200) {
			std::sprintf(buf, "time %.2fs", elapsed * (1.0/CLOCKS_PER_SEC));
			info.push_back(buf);
		}
		
		if (expected == received) {
			verdict = "PASSED";
		} else {
			verdict = "FAILED";
		}
		
		std::cerr << verdict;
		if (!info.empty()) {
			std::cerr << " (";
			for (size_t i=0; i<info.size(); ++i) {
				if (i > 0) std::cerr << ", ";
				std::cerr << info[i];
			}
			std::cerr << ")";
		}
		std::cerr << std::endl;
		
		if (verdict == "FAILED") {
			std::cerr << "    Expected: " << expected << std::endl; 
			std::cerr << "    Received: " << received << std::endl; 
		}
		
		return verdict == "PASSED";
	}

	int run_test_case(int casenum__) {
		switch (casenum__) {
		case 0: {
			string languages[]        = {"This is an English sentence.",
 "Dieser ist ein Deutscher Satz.",
 "C'est une phrase Francaise.",
 "Dit is een Nederlandse zin."
};
			string text               = "In welke taal is deze zin geschreven?";
			int expected__            = 3;

			std::clock_t start__      = std::clock();
			int received__            = LanguageRecognition().whichLanguage(vector <string>(languages, languages + (sizeof languages / sizeof languages[0])), text);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 1: {
			string languages[]        = {"aaaaa","bbbb","ccc","dd","e"};
			string text               = "xxx";
			int expected__            = 0;

			std::clock_t start__      = std::clock();
			int received__            = LanguageRecognition().whichLanguage(vector <string>(languages, languages + (sizeof languages / sizeof languages[0])), text);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 2: {
			string languages[]        = {"AABB","AaBb","A? B!","ab!@#$%"};
			string text               = "ab";
			int expected__            = 0;

			std::clock_t start__      = std::clock();
			int received__            = LanguageRecognition().whichLanguage(vector <string>(languages, languages + (sizeof languages / sizeof languages[0])), text);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}

		// custom cases

/*      case 3: {
			string languages[]        = ;
			string text               = ;
			int expected__            = ;

			std::clock_t start__      = std::clock();
			int received__            = LanguageRecognition().whichLanguage(vector <string>(languages, languages + (sizeof languages / sizeof languages[0])), text);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}*/
/*      case 4: {
			string languages[]        = ;
			string text               = ;
			int expected__            = ;

			std::clock_t start__      = std::clock();
			int received__            = LanguageRecognition().whichLanguage(vector <string>(languages, languages + (sizeof languages / sizeof languages[0])), text);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}*/
/*      case 5: {
			string languages[]        = ;
			string text               = ;
			int expected__            = ;

			std::clock_t start__      = std::clock();
			int received__            = LanguageRecognition().whichLanguage(vector <string>(languages, languages + (sizeof languages / sizeof languages[0])), text);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}*/
		default:
			return -1;
		}
	}
}

#include <cstdlib>
int main(int argc, char *argv[]) {
	if (argc == 1) {
		moj_harness::run_test();
	} else {
		for (int i=1; i<argc; ++i)
			moj_harness::run_test(std::atoi(argv[i]));
	}
}
// END CUT HERE

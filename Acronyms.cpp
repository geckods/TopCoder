#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

class Acronyms {
	public:
 	string acronize(vector <string> document) {
		
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
	
	int verify_case(int casenum, const string &expected, const string &received, std::clock_t elapsed) { 
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
			std::cerr << "    Expected: \"" << expected << "\"" << std::endl; 
			std::cerr << "    Received: \"" << received << "\"" << std::endl; 
		}
		
		return verdict == "PASSED";
	}

	int run_test_case(int casenum__) {
		switch (casenum__) {
		case 0: {
			string document[]         = {"We the people of the United States of America."};
			string expected__         = "We the people of the USA.";

			std::clock_t start__      = std::clock();
			string received__         = Acronyms().acronize(vector <string>(document, document + (sizeof document / sizeof document[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 1: {
			string document[]         = {"Don't","worry.","Be","Happy!"};
			string expected__         = "Don't worry. BH!";

			std::clock_t start__      = std::clock();
			string received__         = Acronyms().acronize(vector <string>(document, document + (sizeof document / sizeof document[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 2: {
			string document[]         = {"Entering contests at TopCoder, Inc.", "is a good way to develop your skills."};
			string expected__         = "Entering contests at TCI. is a good way to develop your skills.";

			std::clock_t start__      = std::clock();
			string received__         = Acronyms().acronize(vector <string>(document, document + (sizeof document / sizeof document[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 3: {
			string document[]         = {"Working at the United States Postal Service",
 "in the United States of America",
 "is a satisfying experience."};
			string expected__         = "Working at the USPS in the USA is a satisfying experience.";

			std::clock_t start__      = std::clock();
			string received__         = Acronyms().acronize(vector <string>(document, document + (sizeof document / sizeof document[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 4: {
			string document[]         = {"a A & a & a B"};
			string expected__         = "a A & a & a B";

			std::clock_t start__      = std::clock();
			string received__         = Acronyms().acronize(vector <string>(document, document + (sizeof document / sizeof document[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 5: {
			string document[]         = {"The First word can't be included.  In","A sequence, that is."};
			string expected__         = "The First word can't be included.  In A sequence, that is.";

			std::clock_t start__      = std::clock();
			string received__         = Acronyms().acronize(vector <string>(document, document + (sizeof document / sizeof document[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 6: {
			string document[]         = {"A Test & Test & & TEst"};
			string expected__         = "A TT & & TEst";

			std::clock_t start__      = std::clock();
			string received__         = Acronyms().acronize(vector <string>(document, document + (sizeof document / sizeof document[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 7: {
			string document[]         = {"This is a TEST tEST Test. ", ".Go Test"};
			string expected__         = "This is a TESTT.  .Go Test";

			std::clock_t start__      = std::clock();
			string received__         = Acronyms().acronize(vector <string>(document, document + (sizeof document / sizeof document[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}

		// custom cases

/*      case 8: {
			string document[]         = ;
			string expected__         = ;

			std::clock_t start__      = std::clock();
			string received__         = Acronyms().acronize(vector <string>(document, document + (sizeof document / sizeof document[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}*/
/*      case 9: {
			string document[]         = ;
			string expected__         = ;

			std::clock_t start__      = std::clock();
			string received__         = Acronyms().acronize(vector <string>(document, document + (sizeof document / sizeof document[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}*/
/*      case 10: {
			string document[]         = ;
			string expected__         = ;

			std::clock_t start__      = std::clock();
			string received__         = Acronyms().acronize(vector <string>(document, document + (sizeof document / sizeof document[0])));
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

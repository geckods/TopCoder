#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

class ColorCode {
  public:
  long long getOhms(vector <string> code) {
    map<string,long long> myMap;
    myMap["black"]=0; 
    myMap["brown"]=1; 
    myMap["red"]=2;
    myMap["orange"]=3;
    myMap["yellow"]=4;
    myMap["green"]=5;
    myMap["blue"]=6;
    myMap["violet"]=7;
    myMap["grey"]=8;
    myMap["white"]=9;

    // cerr<<code[0]<<" "<<myMap[code[0]]<<endl;

    ll ans=(myMap[code[0]]*10+myMap[code[1]])*pow((ll)10,myMap[code[2]]);
    return ans;
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
	
	int verify_case(int casenum, const long long &expected, const long long &received, std::clock_t elapsed) { 
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
			string code[]             = { "yellow", "violet", "red" };
			long long expected__      = 4700;

			std::clock_t start__      = std::clock();
			long long received__      = ColorCode().getOhms(vector <string>(code, code + (sizeof code / sizeof code[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 1: {
			string code[]             = { "orange", "red", "blue" };
			long long expected__      = 32000000;

			std::clock_t start__      = std::clock();
			long long received__      = ColorCode().getOhms(vector <string>(code, code + (sizeof code / sizeof code[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 2: {
			string code[]             = { "white", "white", "white" };
			long long expected__      = 99000000000LL;

			std::clock_t start__      = std::clock();
			long long received__      = ColorCode().getOhms(vector <string>(code, code + (sizeof code / sizeof code[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}

		// custom cases

/*      case 3: {
			string code[]             = ;
			long long expected__      = ;

			std::clock_t start__      = std::clock();
			long long received__      = ColorCode().getOhms(vector <string>(code, code + (sizeof code / sizeof code[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}*/
/*      case 4: {
			string code[]             = ;
			long long expected__      = ;

			std::clock_t start__      = std::clock();
			long long received__      = ColorCode().getOhms(vector <string>(code, code + (sizeof code / sizeof code[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}*/
/*      case 5: {
			string code[]             = ;
			long long expected__      = ;

			std::clock_t start__      = std::clock();
			long long received__      = ColorCode().getOhms(vector <string>(code, code + (sizeof code / sizeof code[0])));
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

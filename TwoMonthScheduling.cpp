#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

class TwoMonthScheduling {
	public:
 	int minimumMonths(int workers, vector <int> firstMonth0, vector <int> firstMonth1, vector <int> secondMonth0, vector <int> secondMonth1) {
		
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
			int workers               = 1000;
			int firstMonth0[]         = {900, 150, 300, 200};
			int firstMonth1[]         = {0};
			int secondMonth0[]        = {400, 300, 600, 150};
			int secondMonth1[]        = {0};
			int expected__            = 4;

			std::clock_t start__      = std::clock();
			int received__            = TwoMonthScheduling().minimumMonths(workers, vector <int>(firstMonth0, firstMonth0 + (sizeof firstMonth0 / sizeof firstMonth0[0])), vector <int>(firstMonth1, firstMonth1 + (sizeof firstMonth1 / sizeof firstMonth1[0])), vector <int>(secondMonth0, secondMonth0 + (sizeof secondMonth0 / sizeof secondMonth0[0])), vector <int>(secondMonth1, secondMonth1 + (sizeof secondMonth1 / sizeof secondMonth1[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 1: {
			int workers               = 1000;
			int firstMonth0[]         = {900, 150, 300, 200};
			int firstMonth1[]         = {0};
			int secondMonth0[]        = {400, 600, 300, 150};
			int secondMonth1[]        = {0};
			int expected__            = 5;

			std::clock_t start__      = std::clock();
			int received__            = TwoMonthScheduling().minimumMonths(workers, vector <int>(firstMonth0, firstMonth0 + (sizeof firstMonth0 / sizeof firstMonth0[0])), vector <int>(firstMonth1, firstMonth1 + (sizeof firstMonth1 / sizeof firstMonth1[0])), vector <int>(secondMonth0, secondMonth0 + (sizeof secondMonth0 / sizeof secondMonth0[0])), vector <int>(secondMonth1, secondMonth1 + (sizeof secondMonth1 / sizeof secondMonth1[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 2: {
			int workers               = 1000;
			int firstMonth0[]         = {350, 172, 24};
			int firstMonth1[]         = {998, 54};
			int secondMonth0[]        = {513, 119, 0};
			int secondMonth1[]        = {24, 118};
			int expected__            = 7;

			std::clock_t start__      = std::clock();
			int received__            = TwoMonthScheduling().minimumMonths(workers, vector <int>(firstMonth0, firstMonth0 + (sizeof firstMonth0 / sizeof firstMonth0[0])), vector <int>(firstMonth1, firstMonth1 + (sizeof firstMonth1 / sizeof firstMonth1[0])), vector <int>(secondMonth0, secondMonth0 + (sizeof secondMonth0 / sizeof secondMonth0[0])), vector <int>(secondMonth1, secondMonth1 + (sizeof secondMonth1 / sizeof secondMonth1[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 3: {
			int workers               = 47;
			int firstMonth0[]         = {0,0,0,0,0,0,1,0,0,0};
			int firstMonth1[]         = {0,0,0,0,0,0,0,0,0,0};
			int secondMonth0[]        = {0,0,0,0,0,0,0,0,0,0};
			int secondMonth1[]        = {0,0,0,0,0,0,1,0,0,0};
			int expected__            = 2;

			std::clock_t start__      = std::clock();
			int received__            = TwoMonthScheduling().minimumMonths(workers, vector <int>(firstMonth0, firstMonth0 + (sizeof firstMonth0 / sizeof firstMonth0[0])), vector <int>(firstMonth1, firstMonth1 + (sizeof firstMonth1 / sizeof firstMonth1[0])), vector <int>(secondMonth0, secondMonth0 + (sizeof secondMonth0 / sizeof secondMonth0[0])), vector <int>(secondMonth1, secondMonth1 + (sizeof secondMonth1 / sizeof secondMonth1[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}

		// custom cases

/*      case 4: {
			int workers               = ;
			int firstMonth0[]         = ;
			int firstMonth1[]         = ;
			int secondMonth0[]        = ;
			int secondMonth1[]        = ;
			int expected__            = ;

			std::clock_t start__      = std::clock();
			int received__            = TwoMonthScheduling().minimumMonths(workers, vector <int>(firstMonth0, firstMonth0 + (sizeof firstMonth0 / sizeof firstMonth0[0])), vector <int>(firstMonth1, firstMonth1 + (sizeof firstMonth1 / sizeof firstMonth1[0])), vector <int>(secondMonth0, secondMonth0 + (sizeof secondMonth0 / sizeof secondMonth0[0])), vector <int>(secondMonth1, secondMonth1 + (sizeof secondMonth1 / sizeof secondMonth1[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}*/
/*      case 5: {
			int workers               = ;
			int firstMonth0[]         = ;
			int firstMonth1[]         = ;
			int secondMonth0[]        = ;
			int secondMonth1[]        = ;
			int expected__            = ;

			std::clock_t start__      = std::clock();
			int received__            = TwoMonthScheduling().minimumMonths(workers, vector <int>(firstMonth0, firstMonth0 + (sizeof firstMonth0 / sizeof firstMonth0[0])), vector <int>(firstMonth1, firstMonth1 + (sizeof firstMonth1 / sizeof firstMonth1[0])), vector <int>(secondMonth0, secondMonth0 + (sizeof secondMonth0 / sizeof secondMonth0[0])), vector <int>(secondMonth1, secondMonth1 + (sizeof secondMonth1 / sizeof secondMonth1[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}*/
/*      case 6: {
			int workers               = ;
			int firstMonth0[]         = ;
			int firstMonth1[]         = ;
			int secondMonth0[]        = ;
			int secondMonth1[]        = ;
			int expected__            = ;

			std::clock_t start__      = std::clock();
			int received__            = TwoMonthScheduling().minimumMonths(workers, vector <int>(firstMonth0, firstMonth0 + (sizeof firstMonth0 / sizeof firstMonth0[0])), vector <int>(firstMonth1, firstMonth1 + (sizeof firstMonth1 / sizeof firstMonth1[0])), vector <int>(secondMonth0, secondMonth0 + (sizeof secondMonth0 / sizeof secondMonth0[0])), vector <int>(secondMonth1, secondMonth1 + (sizeof secondMonth1 / sizeof secondMonth1[0])));
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

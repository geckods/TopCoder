#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

class MeanMedian {
	public:
 	int minEffort(int needMean, int needMedian, vector <int> d) {
		int n = d.size();
		int needTot = needMean*n;

		sort(d.begin(),d.end());
		vector<int> newVec(n);
		for(int i=0;i<n;i++){
			newVec[i]=0;
		}

		int ans=0;
		int gp=0;
		for(int i=0;i<=n/2;i++){
			ans+=needMedian*d[i];
			gp+=needMedian;
			newVec[i]=needMedian;
		}

		needTot-=gp;

		for(int i=0;i<n;i++){
			if(needTot<=0)break;
			if(needTot>=10-newVec[i]){
				ans+=(10-newVec[i])*d[i];
				needTot-=10-newVec[i];
			}
			else{
				ans+=needTot*d[i];
				needTot=0;
			}
		}
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
			int needMean              = 2;
			int needMedian            = 4;
			int d[]                   = {30, 25, 20};
			int expected__            = 180;

			std::clock_t start__      = std::clock();
			int received__            = MeanMedian().minEffort(needMean, needMedian, vector <int>(d, d + (sizeof d / sizeof d[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 1: {
			int needMean              = 4;
			int needMedian            = 4;
			int d[]                   = {30, 25, 20};
			int expected__            = 260;

			std::clock_t start__      = std::clock();
			int received__            = MeanMedian().minEffort(needMean, needMedian, vector <int>(d, d + (sizeof d / sizeof d[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 2: {
			int needMean              = 10;
			int needMedian            = 3;
			int d[]                   = {1, 4, 3, 2, 1};
			int expected__            = 110;

			std::clock_t start__      = std::clock();
			int received__            = MeanMedian().minEffort(needMean, needMedian, vector <int>(d, d + (sizeof d / sizeof d[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 3: {
			int needMean              = 0;
			int needMedian            = 0;
			int d[]                   = {1000};
			int expected__            = 0;

			std::clock_t start__      = std::clock();
			int received__            = MeanMedian().minEffort(needMean, needMedian, vector <int>(d, d + (sizeof d / sizeof d[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 4: {
			int needMean              = 8;
			int needMedian            = 3;
			int d[]                   = {4, 8, 12, 16, 18, 20, 22, 23, 24};
			int expected__            = 1046;

			std::clock_t start__      = std::clock();
			int received__            = MeanMedian().minEffort(needMean, needMedian, vector <int>(d, d + (sizeof d / sizeof d[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}

		// custom cases

/*      case 5: {
			int needMean              = ;
			int needMedian            = ;
			int d[]                   = ;
			int expected__            = ;

			std::clock_t start__      = std::clock();
			int received__            = MeanMedian().minEffort(needMean, needMedian, vector <int>(d, d + (sizeof d / sizeof d[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}*/
/*      case 6: {
			int needMean              = ;
			int needMedian            = ;
			int d[]                   = ;
			int expected__            = ;

			std::clock_t start__      = std::clock();
			int received__            = MeanMedian().minEffort(needMean, needMedian, vector <int>(d, d + (sizeof d / sizeof d[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}*/
/*      case 7: {
			int needMean              = ;
			int needMedian            = ;
			int d[]                   = ;
			int expected__            = ;

			std::clock_t start__      = std::clock();
			int received__            = MeanMedian().minEffort(needMean, needMedian, vector <int>(d, d + (sizeof d / sizeof d[0])));
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

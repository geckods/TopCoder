#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

class FilmSort {
	public:



 	vector <int> sort(vector <int> reels) {
		//when zero is unoccupied, parity must be positive
		//or if zero is occupied, parity must be negative
		int parity=1;
		int n=reels.size();
		if(reels[0]>0){
			parity*=-1;
		}
		for(int i=1;i<n;i++){
			if(reels[i]<0)parity*=-1;
		}

		if(parity==-1 && n<4){
			vector<int> temp;
			temp.push_back(-1);
			return temp;
		}

		vector<int> ans;

		map<int,int>pos;

		if(reels[0]!=0){
			ans.push_back(0);
			int posz=1;
			while(!(reels[posz]==0))posz++;
			reels[posz]=-1*reels[0];
			reels[0]=0;
		}

		pos[0]=0;
		for(int i=0;i<n;i++){
			pos[abs(reels[i])]=i;
		}


		// for(int i=0;i<n;i++){
		// 	cerr<<i<<" "<<reels[i]<<" "<<pos[i]<<endl;
		// }


		for(int i=1;i<n;i++){
			// for(int i=0;i<n;i++){
			// 	cerr<<ans.size()<<endl;
			// 	cerr<<i<<" "<<reels[i]<<" "<<pos[i]<<endl;
			// }
			if(pos[i]!=i){
				int tochange=reels[i];
				int initpos=pos[i];
				ans.push_back(pos[i]);
				ans.push_back(i);
				ans.push_back(0);
				pos[i]=i;
				pos[abs(tochange)]=initpos;
				reels[i]=reels[initpos];
				reels[initpos]=-1*tochange;
			}
		}

		int firstneg=0;
		int secondneg=0;

		// for(int i=0;i<n;i++){
		// 	cerr<<i<<" "<<reels[i]<<" "<<pos[i]<<endl;
		// }


		while(firstneg<n){
			while(firstneg<n && reels[firstneg]>=0){
				firstneg++;
			}
			if(firstneg==n){
				break;
			}
			else{
				secondneg=firstneg+1;
				while(reels[secondneg]>=0)secondneg++;

				ans.push_back(firstneg);
				ans.push_back(secondneg);
				ans.push_back(0);
				ans.push_back(firstneg);
				ans.push_back(secondneg);
				ans.push_back(0);
				firstneg=secondneg+1;
			}
		}
		// for(int i=0;i<n;i++){
		// 	cerr<<i<<" "<<reels[i]<<" "<<pos[i]<<endl;
		// }
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
	
	template<typename T> std::ostream& operator<<(std::ostream &os, const vector<T> &v) { os << "{"; for (typename vector<T>::const_iterator vi=v.begin(); vi!=v.end(); ++vi) { if (vi != v.begin()) os << ","; os << " " << *vi; } os << " }"; return os; }

	int verify_case(int casenum, const vector <int> &expected, const vector <int> &received, std::clock_t elapsed) { 
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
			int reels[]               = {0, 1, 2, 3};
			int expected__[]          = { };

			std::clock_t start__      = std::clock();
			vector <int> received__   = FilmSort().sort(vector <int>(reels, reels + (sizeof reels / sizeof reels[0])));
			return verify_case(casenum__, vector <int>(expected__, expected__ + (sizeof expected__ / sizeof expected__[0])), received__, clock()-start__);
		}
		case 1: {
			int reels[]               = {-2, 1, 0, 3};
			int expected__[]          = {0, 3, 0 };

			std::clock_t start__      = std::clock();
			vector <int> received__   = FilmSort().sort(vector <int>(reels, reels + (sizeof reels / sizeof reels[0])));
			return verify_case(casenum__, vector <int>(expected__, expected__ + (sizeof expected__ / sizeof expected__[0])), received__, clock()-start__);
		}
		case 2: {
			int reels[]               = {2, 0, 1, 3};
			int expected__[]          = {0, 2, 1, 0 };

			std::clock_t start__      = std::clock();
			vector <int> received__   = FilmSort().sort(vector <int>(reels, reels + (sizeof reels / sizeof reels[0])));
			return verify_case(casenum__, vector <int>(expected__, expected__ + (sizeof expected__ / sizeof expected__[0])), received__, clock()-start__);
		}
		case 3: {
			int reels[]               = {0, 1, -2};
			int expected__[]          = {-1 };

			std::clock_t start__      = std::clock();
			vector <int> received__   = FilmSort().sort(vector <int>(reels, reels + (sizeof reels / sizeof reels[0])));
			return verify_case(casenum__, vector <int>(expected__, expected__ + (sizeof expected__ / sizeof expected__[0])), received__, clock()-start__);
		}

		// custom cases

/*      case 4: {
			int reels[]               = ;
			int expected__[]          = ;

			std::clock_t start__      = std::clock();
			vector <int> received__   = FilmSort().sort(vector <int>(reels, reels + (sizeof reels / sizeof reels[0])));
			return verify_case(casenum__, vector <int>(expected__, expected__ + (sizeof expected__ / sizeof expected__[0])), received__, clock()-start__);
		}*/
/*      case 5: {
			int reels[]               = ;
			int expected__[]          = ;

			std::clock_t start__      = std::clock();
			vector <int> received__   = FilmSort().sort(vector <int>(reels, reels + (sizeof reels / sizeof reels[0])));
			return verify_case(casenum__, vector <int>(expected__, expected__ + (sizeof expected__ / sizeof expected__[0])), received__, clock()-start__);
		}*/
/*      case 6: {
			int reels[]               = ;
			int expected__[]          = ;

			std::clock_t start__      = std::clock();
			vector <int> received__   = FilmSort().sort(vector <int>(reels, reels + (sizeof reels / sizeof reels[0])));
			return verify_case(casenum__, vector <int>(expected__, expected__ + (sizeof expected__ / sizeof expected__[0])), received__, clock()-start__);
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

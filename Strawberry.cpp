#include <bits/stdc++.h>
using namespace std;
typedef long long ll;




class Strawberry {
	public:

	int gcdExtended(int a, int b, int *x, int *y); 
  
	// Function to find modulo inverse of a 
	ll modInverse(ll a, ll m) 
	{ 
	    ll x, y; 
	    ll g = gcdExtended(a, m, &x, &y); 
	    if (g != 1) 
	    	return -1;
	    else
	    { 
	        // m is added to handle negative x 
	        ll res = (x%m + m) % m; 
	        return res;
	    } 
	} 
	  
	// C function for extended Euclidean Algorithm 
	ll gcdExtended(ll a, ll b, ll *x, ll *y) 
	{ 
	    // Base Case 
	    if (a == 0) 
	    { 
	        *x = 0, *y = 1; 
	        return b; 
	    } 
	  
	    ll x1, y1; // To store results of recursive call 
	    ll gcd = gcdExtended(b%a, a, &x1, &y1); 
	  
	    // Update x and y using results of recursive 
	    // call 
	    *x = y1 - (b/a) * x1; 
	    *y = x1; 
	  
	    return gcd; 
	} 


	// Function to return gcd of a and b 
	ll gcd(ll a, ll b) 
	{ 
	    if (a == 0) 
	        return b; 
	    return gcd(b%a, a); 
	} 
	  
	// Function to convert the obtained fraction 
	// into it's simplest form 
	void lowest(ll &den3, ll &num3) 
	{ 
	    // Finding gcd of both terms 
	    int common_factor = gcd(num3,den3); 
	  
	    // Converting both terms into simpler  
	    // terms by dividing them by common factor  
	    den3 = den3/common_factor; 
	    num3 = num3/common_factor; 
	} 
	  
	//Function to add two fractions 
	void addFraction(ll num1, ll den1, ll num2,  
	                 ll den2, ll &num3, ll &den3) 
	{ 
	    // Finding gcd of den1 and den2 
	    den3 = gcd(den1,den2); 
	  
	    // Denominator of final fraction obtained 
	    // finding LCM of den1 and den2 
	    // LCM * GCD = a * b  
	    den3 = (den1*den2) / den3; 
	  
	    // Changing the fractions to have same denominator 
	    // Numerator of the final fraction obtained 
	    num3 = (num1)*(den3/den1) + (num2)*(den3/den2); 
	  
	    // Calling function to convert final fraction 
	    // into it's simplest form 
	    lowest(den3,num3); 
	}

 	int competitive(int n, int k, vector <int> A, vector <int> B) {
		//first guy will play n+1/2 turns

		// ll first=(n+1)/2;
		// ll second=(n)/2;


		ll firstsum=0;
		ll secondsum=0;

		for(int i=0;i<A.size();i++){
			firstsum+=A[i];
			secondsum+=B[i];
		}

 		ll probdist[n][2*n*2*k+1][2];
 		for(int i=0;i<n;i++){
 			for(int j=-n*2*k;j<n*2*k+1;j++){
 				probdist[i][j+n*2*k][0]=0;
 				probdist[i][j+n*2*k][1]=1;
 			}
 		}

 		for(int turn=1;turn<=n;turn++){
	 		cerr<<"HI"<<endl;
 			if(turn%2==1){
 				//first guy plays
 				for(int i=-(turn/2)*2*k;i<((turn+1)/2)*2*k+1;i++){
 					//i is the difference
 					if(turn==1){
 						if(i<0) continue;
 						probdist[turn-1][i][0]=A[i];
 						probdist[turn-1][i][1]=firstsum;
 					}
 					else{
 						for(int j=max(-(turn/2)*2*k,i-2*k);j<=i;j++){
 							ll num,dem;
 							addFraction(probdist[turn-1][i+(turn/2)*2*k][0], probdist[turn-1][i+(turn/2)*2*k][1], probdist[turn-2][j][0]*A[i-j], probdist[turn-2][j][1]*firstsum, num, dem);
 							probdist[turn-1][i+(turn/2)*2*k][0]=num;
 							probdist[turn-1][i+(turn/2)*2*k][1]=dem;
 						}
 					}
 				}
 			}
 			else{
 				//second guy plays
 				for(int i=-(turn/2)*2*k;i<((turn+1)/2)*2*k+1;i++){
 					for(int j=min(((turn+1)/2)*2*k,i+2*k);j>=i;j--){
 						ll num,dem;
 						addFraction(probdist[turn-1][i+(turn/2)*2*k][0], probdist[turn-1][i+(turn/2)*2*k][1], probdist[turn-2][j][0]*B[i-j], probdist[turn-2][j][1]*secondsum, num, dem);
 						probdist[turn-1][i+(turn/2)*2*k][0]=num;
 						probdist[turn-1][i+(turn/2)*2*k][1]=dem;
 					}
 				}
 			}
 		}

 		for(int i=0;i<((n+1)/2)*2*k+1;i++){
 			cerr<<i<<" "<<probdist[n-1][i][0]<<" "<<probdist[n-1][i][1]<<endl;
 		}

 		ll ansnum=0;
 		ll ansdem=1;

 		for(int i=-k;i<=k;i++){
 			ll num,dem;
 			addFraction(probdist[n-1][i][0], probdist[n-1][i][1], ansnum, ansdem, num, dem); 			
 			ansnum=num;
 			ansdem=dem;
 		}

 		return (int)(ansnum*modInverse(ansdem,(10e9)+7));

		// ll fpd[2*k*first+1][first];
		// for(int i=0;i<2*k*first+1;i++){
		// 	for(int j=0;j<first;j++){
		// 		fpd[i][j]=0;
		// 	}
		// }

		// for(int turn=1;turn<=first;turn++){
		// 	for(int j=0;j<=turn*2*k;j++){
		// 		if(turn==1){
		// 			fpd[j][turn-1]=A[j];
		// 		}
		// 		else{
		// 			// fpd[j][turn-1]=0;
		// 			for(int z=max(0,j-2*k);z<=j;z++){
		// 				fpd[j][turn-1]+=fpd[z][turn-2]*A[j-z];
		// 			}
		// 		}
		// 	}
		// }

		// for(int i=0;i<2*k*first+1;i++){
		// 	cout<<i<<" "<<fpd[i][first-1]<<endl;
		// }

		// return 0;

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
			int n                     = 1;
			int k                     = 3;
			int A[]                   = {1,1,1,1,1,1,1};
			int B[]                   = {1,1,1,1,1,1,1};
			int expected__            = 571428576;

			std::clock_t start__      = std::clock();
			int received__            = Strawberry().competitive(n, k, vector <int>(A, A + (sizeof A / sizeof A[0])), vector <int>(B, B + (sizeof B / sizeof B[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 1: {
			int n                     = 6;
			int k                     = 3;
			int A[]                   = {4,7,0,0,0,0,0};
			int B[]                   = {4,2,0,0,0,0,0};
			int expected__            = 1;

			std::clock_t start__      = std::clock();
			int received__            = Strawberry().competitive(n, k, vector <int>(A, A + (sizeof A / sizeof A[0])), vector <int>(B, B + (sizeof B / sizeof B[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 2: {
			int n                     = 7;
			int k                     = 3;
			int A[]                   = {4,7,0,0,0,0,0};
			int B[]                   = {4,2,0,0,0,0,0};
			int expected__            = 969874055;

			std::clock_t start__      = std::clock();
			int received__            = Strawberry().competitive(n, k, vector <int>(A, A + (sizeof A / sizeof A[0])), vector <int>(B, B + (sizeof B / sizeof B[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 3: {
			int n                     = 50;
			int k                     = 5;
			int A[]                   = {100,101,102,103,104,105,106,107,108,109,110};
			int B[]                   = {200,101,202,203,204,205,206,207,208,209,210};
			int expected__            = 440607283;

			std::clock_t start__      = std::clock();
			int received__            = Strawberry().competitive(n, k, vector <int>(A, A + (sizeof A / sizeof A[0])), vector <int>(B, B + (sizeof B / sizeof B[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}

		// custom cases

/*      case 4: {
			int n                     = ;
			int k                     = ;
			int A[]                   = ;
			int B[]                   = ;
			int expected__            = ;

			std::clock_t start__      = std::clock();
			int received__            = Strawberry().competitive(n, k, vector <int>(A, A + (sizeof A / sizeof A[0])), vector <int>(B, B + (sizeof B / sizeof B[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}*/
/*      case 5: {
			int n                     = ;
			int k                     = ;
			int A[]                   = ;
			int B[]                   = ;
			int expected__            = ;

			std::clock_t start__      = std::clock();
			int received__            = Strawberry().competitive(n, k, vector <int>(A, A + (sizeof A / sizeof A[0])), vector <int>(B, B + (sizeof B / sizeof B[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}*/
/*      case 6: {
			int n                     = ;
			int k                     = ;
			int A[]                   = ;
			int B[]                   = ;
			int expected__            = ;

			std::clock_t start__      = std::clock();
			int received__            = Strawberry().competitive(n, k, vector <int>(A, A + (sizeof A / sizeof A[0])), vector <int>(B, B + (sizeof B / sizeof B[0])));
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

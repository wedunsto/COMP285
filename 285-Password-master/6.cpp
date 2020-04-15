#include <iostream>
#include "pass.h"
#include <math.h>  
#include <fstream>
using namespace std;

ofstream fout("permutations.txt");

string itos(int n) {
    string num;

    switch (n) {
        case 0:
            num = "0" + num;
            break;
        case 1:
            num = "1" + num;
            break;
        case 2:
            num = "2" + num;
            break;
        case 3:
            num = "3" + num;
            break;
        case 4:
            num = "4" + num;
            break;
        case 5:
            num = "5" + num;
            break;
        case 6:
            num = "6" + num;
            break;
        case 7:
            num = "7" + num;
            break;
        case 8:
            num = "8" + num;
            break;
        case 9:
            num = "9" + num;
            break;
    }

    return num;
}

int toBinary(int n) {
    int power = 0;
    int binary = 0;
    while (n != 0) {
        binary += n % 2 * (int) pow(10, power);
        n = n / 2;
        power++;
    }
    return binary;
}

int countOnes(int n) {
    int count = 0;

    while (n != 0) {
        if (n % 10 == 1) {
            count++;
        }
        n = n / 10;
    }
    return count;
}

//Given code for permutation

void findi(int a[], int n, int &i) {
    i = 0;
    for (int k = 0; k < n - 1; k++) {
        if (a[k] < a[k + 1])
            i = k;
    }
}

void findj(int a[], int n, int i, int &j) {
    j = i + 1;
    for (int k = i + 1; k < n; k++) {
        if (a[k] > a[i]) {
            if (a[k] < a[j]) j = k;
        }
    }
}

void switch_i_j(int i, int j, int a[]) {
    int num;
    num = a[i];
    a[i] = a[j];
    a[j] = num;
}

void reversetail(int n, int i, int a[]) {
    int b[25], k;
    for (k = i + 1; k < n; k++)
        b[k] = a[n - k + (i + 1) - 1];
    for (k = i + 1; k < n; k++)
        a[k] = b[k];
}

//changed initial to 0 through n-1, instead of 1 through n
void initial(int a[], int n) {
    int k;
    for (k = 0; k < n; k++)
        a[k] = k;
}

long nfact(int n) {
    int k;
    long p = 1;
    for (k = 1; k <= n; k++)
        p = p * k;
    return p;
}

void permute(int n, int permutedArray[]) {
    int a[10];
    int i, j, y, permuted = 0;
    initial(a, n);
    for (int x = 0; x <= n - 1; x++)
// permuted += a[x] * (int) pow(10, x);
    
//save result to array instead of a file
//permutedArray[0] = permuted;
fout<<a[x];
fout<<endl;
    
    for (int x = 1; x < nfact(n); x++) {
        findi(a, n, i);
        findj(a, n, i, j);
        switch_i_j(i, j, a);
        reversetail(n, i, a);
        for (y = 0; y <= n - 1; y++)
//permutedArray[x] += a[y] * (int) pow(10, y);
fout<<a[y];
fout<<endl;
    }
}

int main(int argc, char* argv[]) {
    if (argc > 1) {
        int k = atoi(argv[1]);
        int numPermutations = nfact(k);
	int *permutedArray = new int[numPermutations];
	permute(k, permutedArray);
	fout.close();
        
        
        //calculate min binary
        int minBinary = 0;
        for (int i = 0; i < k; i++) {
            minBinary += (int) pow(2, i);
        }

        //calculate max binary
        int maxBinary = 0;
        for (int i = 9; i > (9 - k); i--) {
            maxBinary += (int) pow(2, i);
        }

        int *subsetArray = new int[k];

        //loop through binary number to find subsets
        for (int i = minBinary; i <= maxBinary; i++) {
            //convert i to binary
            int binarySubset = toBinary(i);
            //check for k ones
            if (countOnes(binarySubset) == k) {
                //convert binarySubset to a decimal subset
                int index = 0;
                int decimal = 0;
                while (binarySubset != 0) {
                    if (binarySubset % 10 == 1) {
                        subsetArray[index] = decimal;
                        index++;
                    }
                    binarySubset = binarySubset / 10;
                    decimal++;
                }
                //loop through permutations of the subset
ifstream fin("permutations.txt");                
                for (int j = 0; j < numPermutations; j++) {
//int tempPermutation = permutedArray[j];
char input[3];
fin >> input;
int tempPermutation = atoi(input);
                    
                    string password = "";
                    for (int h = 0; h < k; h++) {
                        int permuteIndex = tempPermutation % 10;
                        tempPermutation = tempPermutation / 10;
                        password = itos(subsetArray[permuteIndex]) + password;
                    }
                    //check password with pass()
                    const char* b = password.c_str();
                    char * c = (char*)b;

                    //print list of passwords, the c-string version, and the result of pass()
//                    cout << password << " " <<c<<" "<<pass(c)<<endl;
                    
                  if(pass(c)==0){
                      cout << "Correct Password: "<<password <<endl;
                      return 0;
                    }
                }
fin.close();
            }
        }
        
        return 0;
    }
    return -1;
}

#include <iostream>
#include <cmath>
using namespace std;

void permutation(int n, int container[], int factorial);

int main() {
    int n;
    signed long int factorial = 1;


    cout << "Please enter an integer between 1 and 25: ";
    cin >> n;

    while (isnan(n) || n < 0 || n > 25){
        cout << "That value is not valid. Please enter a number between 1 and 25.";
        cin >> n;}
    for(int i = n; i > 0; i-- ){
        factorial = factorial * i;
    }
    int container[n-1];

    for(int i = n; i >= 1; i-- ){
        container[i-1] = i;
    }

    cout << "There are " << factorial << " permutations of the set {" ;
    for(int i = 0; i <= (n-1) ; i++ ){
        if (i != n-1){
            cout << container[i] << ", ";}
        else{
            cout << container[i];
        }
    }
    cout << "}" << endl;

    permutation(n, container, factorial);

    return 0;
}


void permutation(int n, int container[], int factorial) {

    int perm = (factorial / n);
    if (n == 1){
        cout << "1";
    }
    else if(n == 2){
        cout << "{ 1, 2}" << endl << "{ 2, 1}" << endl;
    }
    //this loop ensures that we pass through each possible number in the array in slot 0
 if(n % 2 == 0){

    for (int m = 0; m <= n - 1; m++) {
        //this loop makes sure that we go through each possible number in slot zero as well
        //tried changing perm/2 to perm/3 and that made it so it only printed 3 of the 4 different leading numbers

        for (int j = perm / 2; j > 0; j--) {
            //for (int i = perm; i >= (perm / 2); i--) {
            int temp = container[1];
            container[1] = container[n - 1];
            container[n - 1] = temp;


            cout << "{";
            for (int k = 0; k <= (n - 1); k++) {
                if (k != n - 1) {
                    cout << container[k] << ", ";
                } else {
                    cout << container[k] << "}" << endl;

                }

            }

            //if there are more than two items in the list, swap the middle item with the item after it and keep doing that until we get to the end
            if (n > 2) {
                for (int l = 1; l < (n - 2); l++) {
                    int temp = container[l];
                    container[l] = container[l + 1];
                    container[l + 1] = temp;
                }
                cout << "{";
                for (int k = 0; k <= (n - 1); k++) {
                    if (k != n - 1) {
                        cout << container[k] << ", ";
                    } else {
                        cout << container[k] << "}" << endl;

                    }
                }


            }
        }

        //NO TOUCHY!!!!
        for (int j = perm / 2; j >= 0; j--) {
            //if (j != 0) {
            int temp = container[j];
            container[j] = container[n - 1];
            container[n - 1] = temp;


            //go ahead and print that since it's a new permutation
            /*    cout << "{";
                for (int k = 0; k <= (n - 1); k++) {
                    if (k != n - 1) {
                        cout << container[k] << ", ";
                    } else {
                        cout << container[k] << "}" << endl;

                    }
                }*/
        }

    }

    for (int q = 0; q <= n - 1; q++) {

        if (container[q] == (container[0] + 1)) {
            int temp = container[q];
            container[q] = container[0];
            container[0] = temp;
        }

    }
}



if (n % 2 != 0 && n > 1 ) {

    }
    for (int m = 0; m <= n - 1; m++) {
        //this loop makes sure that we go through each possible number in slot zero as well
        //tried changing perm/2 to perm/3 and that made it so it only printed 3 of the 4 different leading numbers

        for (int j = 0; j < (perm + 1) / 2; j++) {
            //for (int i = perm; i >= (perm / 2); i--) {
            int temp = container[1];
            container[1] = container[n - 1];
            container[n - 1] = temp;


            cout << "{";
            for (int k = 0; k <= (n - 1); k++) {
                if (k != n - 1) {
                    cout << container[k] << ", ";
                } else {
                    cout << container[k] << "}" << endl;

                }

            }

            //if there are more than two items in the list, swap the middle item with the item after it and keep doing that until we get to the end
            if (n > 3) {
                for (int l = 0; l < (n - 1); l++) {
                    int temp = container[l];
                    container[l] = container[l + 1];
                    container[l + 1] = temp;
                }
                cout << "{";
                for (int k = 0; k <= (n - 1); k++) {
                    if (k != n - 1) {
                        cout << container[k] << ", ";
                    } else {
                        cout << container[k] << "}" <<endl;

                    }
                }


            }
        }

        //NO TOUCHY!!!!
        for (int j = (perm) / 2; j >= 0; j--) {
            //if (j != 0) {
            int temp = container[j];
            container[j] = container[n - 1];
            container[n - 1] = temp;


            //go ahead and print that since it's a new permutation
            if (container[0] > j) {
                cout << "{";
                for (int k = 0; k <= (n - 1); k++) {
                    if (k != n - 1) {
                        cout << container[k] << ", ";
                    } else {
                        cout << container[k] << "}" <<  endl;

                    }
                }
            }
        }

        for (int q = 0; q <= n - 1; q++) {

            if (container[q] == (container[0] + 1)) {
                int temp = container[q];
                container[q] = container[0];
                container[0] = temp;

                break;
            }

        }
    }
}



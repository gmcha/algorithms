#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

// prints content of the vector v
void print(const vector<int>& v){
    for(int elem : v)
        cout << elem << " ";
    cout << "\n";
}

// determines primality of a given value n
// returns true if n is prime; otherwise, returns false
bool is_prime(int n) {
    if (n < 2)
        return false;
    else {
        bool result = true;
        double r = n, root = sqrt(r);
        for(int trial_factor = 2; result && trial_factor <= root; trial_factor++)
            result = (n % trial_factor != 0);
        return result;
    }
}

// returns a vector containing the prime numbers in the range begin...end
// begin is the first number in the range, end is the last number in the range
vector<int> primes(int begin, int end){
    vector<int> result;
    for(int i = begin; i <= end; i++)
        if(is_prime(i))
            result.push_back(i);
    return result;
    
}

int main(){
    int low, high;
    cout << "Please enter lowest and highest values in the range: ";
    cin >> low >> high;
    vector<int> prime_list = primes(low, high);
    print(prime_list);
}

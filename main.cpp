#include <iostream>
#include<vector>
#include<chrono>
#include <algorithm>

using namespace std;

void multiplyNaive(const vector<float>& A, const vector<float>& B, vector<float>& C, int N) {

    for (int i=0; i<N; i++) {
        for (int j=0; j<N; j++) {
            for (int k=0; k<N; k++) {
            C[i*N+j] += A[i*N+k] * B[k*N+j];
            }
        }
    }
}

void multiplyOptimized(const vector<float>& A, const vector<float>& B, vector<float>& C, int N) {

    for (int i=0; i<N; i++) {
        for (int k=0; k<N; k++) {
            for (int j=0; j<N; j++) {
                C[i*N+j] += A[i*N+k] * B[k*N+j];
            }
        }
    }
}

int main() {
    int N = 1024;

    vector<float> A(N * N, 1.0f);
    vector<float> B(N * N, 2.0f);
    vector<float> C(N * N, 0.0f);

    auto start1 = chrono::high_resolution_clock::now();

    multiplyNaive(A, B, C, N);

    auto end1 = chrono::high_resolution_clock::now();
    chrono::duration<double> diff1 = end1 - start1;
    cout << "Czas naiwny: " << diff1.count() << " sekund" << endl;

    fill(C.begin(), C.end(), 0.0f);

    auto start2 = chrono::high_resolution_clock::now();

    multiplyOptimized(A, B, C, N);

    auto end2 = chrono::high_resolution_clock::now();
    chrono::duration<double> diff2 = end2 - start2;
    cout << "Czas zoptymalizowanego: " << diff2.count() << " sekund" << endl;

    return 0;
}
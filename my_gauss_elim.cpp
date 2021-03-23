#include "matrix.hpp"
#include "matrix_utility.hpp"

using namespace std;

matrix< double > re (matrix< double > m1, int N) {
    matrix< double > zero(N, 1, 0);
    int temp = 0;
    for (int P = 0 ; P < N - 1; P++) {
        for (int i = P; i < N; i++) {
            cout << m1(span(P, N - 1), span(i, i)) << endl << zero(span(P, N - 1), span(0, 0)) << endl;
            if (m1(span(P, N - 1), span(i, i)) == zero(span(P, N - 1), span(0, 0))) continue;
            else {
                cout << m1 << endl;
                if (m1(P, i) == 0)
                for (int j = P + 1; j < N; j++) {
                    if (m1(j, i) == 0) continue;
                    else {
                        for (int k = 0; k < N; k++) {
                            temp = m1(P, k);
                            m1(P, k) = m1(j, k);
                            m1(j, k) = temp; 
                        }
                        cout << m1<< endl;
                        break;
                    }
                }
                for (int j = P + 1; j < N; j++) {
                    if (m1(j, P) == 0) continue;
                    else {
                        temp = m1(j, P);
                        for (int k = 0; k < N; k++) {
                            double val = m1(j, k) - (m1(P, k) * temp / m1(P, P));
                            m1(j, k) = (fabs(val) < 1e-5) ? 0 : val; //limis to remove error due to double calculations
                        }
                        cout << m1<< endl;
                    }
                }
            }
        }
    }
    return m1;
}

int main() {

    int N = 3; //size of matrix
    matrix < double > orignal = {{3, 2, 1},
                            {2, 1, 1},
                            {6, 2, 4}};

    cout << "Orignal Matrix: \n" << orignal << endl;

    matrix < double > rematrix = re(orignal, N);

    cout << "Matrix in row Echleon Form: \n" << rematrix; 

    return 0;
}
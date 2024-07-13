#include <stdio.h>
#include <time.h>
#include "DNS_QUANTUM.h"

int main() {
    srand(time(NULL));

    Qubit q1;
    Qubit q2;

    State HADAMARD, PAULI_X, PAULI_Y, PAULI_Z;
    initialize_gates(HADAMARD, PAULI_X, PAULI_Y, PAULI_Z);

    init_qubit(&q1);
    init_qubit(&q2);

    apply_gate(&q1, HADAMARD);
    applyCNOT(&q1, &q2, PAULI_X);

    int result1 = measure(&q1);
    int result2 = measure(&q2);

    printf("Measurement results: %d, %d\n", result1, result2);

    return 0;
}
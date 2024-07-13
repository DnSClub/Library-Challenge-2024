#define DNS_QUANTUM_C

#include <math.h>
#include <complex.h>
#include <stdlib.h>
#include <time.h>

typedef double complex Complex;
typedef Complex State[4];  //Holds a 2x2 matrix for gates

typedef struct {
    Complex state[2];
} Qubit;

void init_qubit(Qubit* q) {
    q->state[0] = 1.0 + 0.0 * I;
    q->state[1] = 0.0 + 0.0 * I;
}

void apply_gate(Qubit* q, const State gate) {
    Complex newState[2];
    newState[0] = gate[0] * q->state[0] + gate[1] * q->state[1];
    newState[1] = gate[2] * q->state[0] + gate[3] * q->state[1];
    q->state[0] = newState[0];
    q->state[1] = newState[1];
}

int measure(Qubit* q) {
    double probability0 = pow(cabs(q->state[0]), 2);
    double randomValue = (double)rand() / RAND_MAX;
    return (randomValue < probability0) ? 0 : 1;
}

void initialize_gates(State hadamard, State pauli_x, State pauli_y, State pauli_z) {
    hadamard[0] = 1 / sqrt(2) + 0.0 * I;
    hadamard[1] = 1 / sqrt(2) + 0.0 * I;
    hadamard[2] = 1 / sqrt(2) + 0.0 * I;
    hadamard[3] = -1 / sqrt(2) + 0.0 * I;

    pauli_x[0] = 0.0 + 0.0 * I;
    pauli_x[1] = 1.0 + 0.0 * I;
    pauli_x[2] = 1.0 + 0.0 * I;
    pauli_x[3] = 0.0 + 0.0 * I;

    pauli_y[0] = 0.0 + 0.0 * I;
    pauli_y[1] = 0.0 - 1.0 * I;
    pauli_y[2] = 0.0 + 1.0 * I;
    pauli_y[3] = 0.0 + 0.0 * I;

    pauli_z[0] = 1.0 + 0.0 * I;
    pauli_z[1] = 0.0 + 0.0 * I;
    pauli_z[2] = 0.0 + 0.0 * I;
    pauli_z[3] = -1.0 + 0.0 * I;
}

void applyCNOT(Qubit* control, Qubit* target, const State pauli_x) {
    if (measure(control) == 1) {
        apply_gate(target, pauli_x);
    }
}
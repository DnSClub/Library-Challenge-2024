import DNS_QUANTUM as Q

q1 = Q.Qubit()
q2 = Q.Qubit()

#Apply a Hadamard gate to q1
q1.apply_gate(Q.HADAMARD)

#Apply a CNOT gate with q1 as control and q2 as target
Q.apply_CNOT(q1, q2)

#Measure both qubits
result1 = q1.measure()
result2 = q2.measure()

print(f"Measurement results: {result1}, {result2}")

#ifndef OPERATOR_H
#define OPERATOR_H

/* opérations élémentaires (deux opérandes) */
int somme(int a, int b);
int difference(int a, int b);
int produit(int a, int b);
int quotient(int a, int b); /* division entière, gère division par 0 en appelant */
int modulo(int a, int b);

/* opérations bitwise */
int et_bit(int a, int b);
int ou_bit(int a, int b);

/* négation bitwise : n'utilise que num1 */
int negation(int a);

/* wrapper d'entrée pour l'exercice 4.1 */
void operator_entry(void);

#endif /* OPERATOR_H */

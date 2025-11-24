Step-by-step trace
Initial:
Stack: (empty)
Output: (empty)
Token	Action / Reason	Stack (top→right)	Output (postfix so far)
a	operand → append to output	(empty)	a
-	operator → stack empty → push -	-	a
b	operand → append	-	a b
*	operator * has higher precedence than top - → push *	- *	a b
c	operand → append	- *	a b c
-	operator -: pop while top prec ≥ prec(-) → pop * (2≥1) → output *	-	a b c *
then top - (1≥1) → pop - → output -	(empty)	a b c * -
then push new -	-	a b c * -
d	operand → append	-	a b c * - d
/	/ has higher precedence than top - → push /	- /	a b c * - d
e	operand → append	- /	a b c * - d e
+	+: pop while top prec ≥ prec(+) → pop / (2≥1) → output /	-	a b c * - d e /
then pop - (1≥1) → output -	(empty)	a b c * - d e / -
push +	+	a b c * - d e / -
f	operand → append	+	a b c * - d e / - f
end	pop remaining operators → pop + → output +	(empty)	a b c * - d e / - f +
Final postfix expression
a b c * - d e / - f +
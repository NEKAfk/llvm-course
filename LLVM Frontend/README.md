# PDDLang Reference

- Functions: \
    `let funName(arg0, arg1, ...) -> retType { ... }` \
    where `retType` - `num` or `void`
- Declarations: \
    `num varName = n;` \
    `arr[n0, n1, ...] arrName;` \
    where `n0..n1` - digits
- Expressions in prefix notation: \
    `expr0 = +(expr1, &(expr2, expr3));`
- Array access: \
    `arr[expr0, expr1, ...]`
- if/while statements: \
    `if[cond] {...}` \
    `while[cond] {...}`
- folded for statements:
    ```
    for
    [varName0, start0, end0]
    [varName1, start1, end1].. {... }
    ```
- return statement: \
    `return;` \
    `return expr;`

# Lexical Analysis (Flex)

The Lexical Analyzer is the first phase of the OPEX compiler. It transforms an unformatted stream of source characters into a structured sequence of atomic tokens.

---

## Token Classifications

Tokens in OPEX are categorized into distinct semantic groups:

| Category | Sample Tokens | Regex Pattern |
| :--- | :--- | :--- |
| **Keywords** | `PROGRAM`, `FUNCTION`, `STRUCT`, `VAR`, `AUTO` | Direct string match |
| **CV Keywords** | `IMAGE`, `MATRIX`, `KERNEL`, `PIXEL` | Direct string match |
| **Operators** | `:=`, `**`, `|>`, `+`, `-`, `*`, `/`, `==`, `!=` | Exact operator match |
| **Separators** | `[`, `]`, `(`, `)`, `:`, `;`, `,`, `.` | Single-character punctuation |
| **Identifiers** | `myVar`, `sobelX`, `_temp` | `([a-zA-Z]|_)([a-zA-Z0-9]|_)*` |
| **Integer Literals**| `0`, `42`, `100` | `[0-9]+` |
| **Float Literals** | `3.14`, `0.001` | `[0-9]+\.[0-9]+([eE][+-]?[0-9]+)?` |
| **String Literals** | `"Hello {name}"` | `\"([^\"\\\n]\|\\.)*\"` |

---

## Column & Coordinate Tracking

To enable precise compiler diagnostic reporting, the lexer intercepts token consumption via Flex's `YY_USER_ACTION` macro:

```c
int yycolumn = 1;

#define YY_USER_ACTION \
    yylloc.first_line = yylineno; \
    yylloc.last_line = yylineno; \
    yylloc.first_column = yycolumn; \
    yylloc.last_column = yycolumn + yyleng - 1; \
    yycolumn += yyleng;
```

When a newline `\n` is encountered, `yycolumn` resets to 1, while `yylineno` increments automatically.


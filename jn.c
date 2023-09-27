#include <stdio.h>

/* read the next byte from the C source file, handing escaped newlines */
int getcpp(FILE *fp) {
    int ch;
    while ((ch = getc(fp)) == '\\') {
        if ((ch = getc(fp)) != '\n') {
            ungetc(ch, fp);
            return '\\';
        }
    }
    return ch;
}

/* read and write character and string constants */
int skipstr(int cch, FILE *fp, FILE *ft) {
    int ch;
    putc(cch, ft);
    while ((ch = getcpp(fp)) != EOF) {
        putc(ch, ft);
        if (ch == cch)
            return 0;
        if (ch == '\\') {
            if ((ch = getcpp(fp)) == EOF)
                return EOF;
            putc(ch, ft);
        }
    }
    return EOF;
}

int main(int argc, char *argv[]) {
    FILE *fp, *ft;
    int ch;

    if (argc < 3) {
        fprintf(stderr, "Missing arguments. Need input and output filenames\n");
        return 1;
    }
    if ((fp = fopen(argv[1], "r")) == NULL) {
        fprintf(stderr, "Cannot open input file %s\n", argv[1]);
        return 1;
    }
    if ((ft = fopen(argv[2], "w")) == NULL) {
        fprintf(stderr, "Cannot open output file %s\n", argv[2]);
        return 1;
    }
    while ((ch = getcpp(fp)) != EOF) {
        if (ch == '\'' || ch == '"') {
            if (skipstr(ch, fp, ft)) {
                fprintf(stderr, "unterminated string or character constant\n");
                break;
            }
            continue;
        }
        if (ch == '/') {
            if ((ch = getcpp(fp)) == '*') {
                /* multi-line comment */
                int lastc = 0;
                while ((ch = getcpp(fp)) != EOF) {
                    if (ch == '/' && lastc == '*') {
                        break;
                    }
                    lastc = ch;
                }
                if (ch == EOF) {
                    fprintf(stderr, "unterminated comment\n");
                    break;
                }
                ch = ' ';
            } else if (ch == '/') {
                /* single-line comment */
                while ((ch = getcpp(fp)) != EOF && ch != '\n')
                    continue;
                if (ch == EOF)
                    break;
            } else {
                putc('/', ft);
            }
        }
        putc(ch, ft);
    }
    fclose(fp);
    fclose(ft);
    return 0;
}
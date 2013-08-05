/* gsSeqInfo.h was originally generated by the autoSql program, which also 
 * generated gsSeqInfo.c and gsSeqInfo.sql.  This header links the database and the RAM 
 * representation of objects. */

#ifndef GSSEQINFO_H
#define GSSEQINFO_H

struct gsSeqInfo
/* Greg Schuler format sequence info - describes an accessioned clone */
    {
    struct gsSeqInfo *next;  /* Next in singly linked list. */
    char *acc;	/* Accession.version */
    char gi[13];	/* Genbank GI number */
    unsigned size;	/* Size in bases */
    unsigned phase;	/* 0, 1, 2, or 3 HGP phase */
    char draft[2];	/* - or D depending if considered draft or not */
    char *chrom;	/* Chromosome, sometimes parenthesized */
    char *lab;	/* Sequencing center */
    char *cloneName;	/* Name of BAC or other clone */
    };

void gsSeqInfoStaticLoad(char **row, struct gsSeqInfo *ret);
/* Load a row from gsSeqInfo table into ret.  The contents of ret will
 * be replaced at the next call to this function. */

struct gsSeqInfo *gsSeqInfoLoad(char **row);
/* Load a gsSeqInfo from row fetched with select * from gsSeqInfo
 * from database.  Dispose of this with gsSeqInfoFree(). */

struct gsSeqInfo *gsSeqInfoCommaIn(char **pS, struct gsSeqInfo *ret);
/* Create a gsSeqInfo out of a comma separated string. 
 * This will fill in ret if non-null, otherwise will
 * return a new gsSeqInfo */

void gsSeqInfoFree(struct gsSeqInfo **pEl);
/* Free a single dynamically allocated gsSeqInfo such as created
 * with gsSeqInfoLoad(). */

void gsSeqInfoFreeList(struct gsSeqInfo **pList);
/* Free a list of dynamically allocated gsSeqInfo's */

void gsSeqInfoOutput(struct gsSeqInfo *el, FILE *f, char sep, char lastSep);
/* Print out gsSeqInfo.  Separate fields with sep. Follow last field with lastSep. */

#define gsSeqInfoTabOut(el,f) gsSeqInfoOutput(el,f,'\t','\n');
/* Print out gsSeqInfo as a line in a tab-separated file. */

#define gsSeqInfoCommaOut(el,f) gsSeqInfoOutput(el,f,',',',');
/* Print out gsSeqInfo as a comma separated list including final comma. */

#endif /* GSSEQINFO_H */

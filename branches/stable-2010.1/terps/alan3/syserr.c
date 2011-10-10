#include "syserr.h"

#include "debug.h"
#include "utils.h"
#include "current.h"
#include "output.h"


static void (*handler)(char *) = NULL;

/*----------------------------------------------------------------------*/
static void runtimeError(char *errorClassification, char *errorDescription) {
  output("$n$nAs you enter the twilight zone of Adventures, you stumble \
and fall to your knees. In front of you, you can vaguely see the outlines \
of an Adventure that never was.$n$n");
  output(errorClassification);
  output(errorDescription);
  output("$n$n");

  if (current.sourceLine != 0) {
    printf("At source line %d in '%s':\n", current.sourceLine, sourceFileName(current.sourceFile));
    printf("%s", readSourceLine(current.sourceFile, current.sourceLine));
  }

  newline();

#ifdef __amiga__
#ifdef AZTEC_C
  {
    char buf[80];

    if (con) { /* Running from WB, wait for user ack. */
      printf("press RETURN to quit");
      gets(buf);
    }
  }
#endif
#endif

  terminate(0);
}


/*======================================================================*/
void setSyserrHandler(void (*f)(char *))
{
  handler = f;
}


/*======================================================================*/
// TODO Make syserr() use ... as printf()
void syserr(char *description)
{
    if (handler == NULL) {
        para();
        output("If you are the creator of this piece of Interactive Fiction, \
please help debug this Alan system error. Collect *all* the sources, and, if possible, an \
exact transcript of the commands that let to this error, in a zip-file and send \
it to support@alanif.se. Thank you!");
        runtimeError("SYSTEM ERROR: ", description);
    } else
        handler(description);
}


/*======================================================================*/
void apperr(char *description)
{
    if (handler == NULL) {
        para();
        output("If you are playing this piece of Interactive Fiction, \
please help the author to debug this programming error. Send an exact \
transcript of the commands that let to this error to the author. Thank you!");
        runtimeError("APPLICATION ERROR: ", description);
    } else
        handler(description);
}
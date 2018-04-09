#include "../picoc.h"
#include "../interpreter.h"

/* mark where to end the program for platforms which require this */
jmp_buf PicocExitBuf;

#include <signal.h>

Picoc *break_pc = NULL;

static void BreakHandler(int Signal)
{
    break_pc->DebugManualBreak = TRUE;
}

void PlatformInit(Picoc *pc)
{
    /* capture the break signal and pass it to the debugger */
    break_pc = pc;
    signal(SIGINT, BreakHandler);
}

void PlatformCleanup(Picoc *pc)
{
}

/* get a line of interactive input */
char *PlatformGetLine(char *Buf, int MaxLen, const char *Prompt)
{
    if (Prompt != NULL)
        printf("%s", Prompt);
        
    fflush(stdout);
    return fgets(Buf, MaxLen, stdin);
}

/* get a character of interactive input */
int PlatformGetCharacter()
{
    fflush(stdout);
    return getchar();
}

/* write a character to the console */
void PlatformPutc(unsigned char OutCh, union OutputStreamInfo *Stream)
{
    putchar(OutCh);
}

/* read a file into memory */
char *PlatformReadFile(Picoc *pc, const char *FileName)
{
    ProgramFailNoParser(pc, "can't read file %s\n", FileName);
    return NULL;
}

/* read and scan a file for definitions */
void PicocPlatformScanFile(Picoc *pc, const char *FileName)
{
    char *SourceStr = PlatformReadFile(pc, FileName);

    /* ignore "#!/path/to/picoc" .. by replacing the "#!" with "//" */
    if (SourceStr != NULL && SourceStr[0] == '#' && SourceStr[1] == '!') 
    { 
        SourceStr[0] = '/'; 
        SourceStr[1] = '/'; 
    }

    PicocParse(pc, FileName, SourceStr, strlen(SourceStr), TRUE, FALSE, TRUE, TRUE);
}

/* exit the program */
void PlatformExit(Picoc *pc, int RetVal)
{
    pc->PicocExitValue = RetVal;
    longjmp(pc->PicocExitBuf, 1);
}


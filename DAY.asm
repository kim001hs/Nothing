INCLUDE Irvine32.inc
.386
.model flat, stdcall
.stack 4096
ExitProcess proto, dwExitCode: dword

.data
    SUNDAY      EQU 0
    MONDAY      EQU 1
    TUESDAY     EQU 2
    WEDNESDAY   EQU 3
    THURSDAY    EQU 4
    FRIDAY      EQU 5
    SATURDAY    EQU 6

    daysArray   dd SUNDAY, MONDAY, TUESDAY, WEDNESDAY, THURSDAY, FRIDAY, SATURDAY

.code
main PROC
    call DumpRegs   
    invoke ExitProcess, 0
main ENDP
END main

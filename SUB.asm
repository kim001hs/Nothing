INCLUDE Irvine32.inc

.code
main PROC

	mov eax,60000h
	mov ebx,10000h	
	mov ecx,20000h	

	sub eax,ebx	;eax=eax-ebx(50000h)
	sub eax,ecx	;eax=eax-ecx(30000h)

	call DumpRegs
	exit
main ENDP
END main

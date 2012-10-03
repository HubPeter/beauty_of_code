;hello.asm
section	.data		;数据段说明
	msg	db  'Hello world!', 0xA	;要输出的字符串
	len equ $ - msg	;字符串长度
section	.text		;代码段说明
global	_start		;指定程序入口
_start:
	mov edx, len
	mov ecx, msg
	mov ebx, 1		;文件描述符stdout
	mov eax, 4		;内核调用sys_write
	int 0x80

	mov ebx, 1		;exit code 1
	mov eax, 4		;内核调用sys_exit
	int 0x80
	

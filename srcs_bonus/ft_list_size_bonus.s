; **************************************************************************** ;
;                                                                              ;
;                                                         :::      ::::::::    ;
;    ft_list_size_bonus.s                               :+:      :+:    :+:    ;
;                                                     +:+ +:+         +:+      ;
;    By: vvaucoul <vvaucoul@student.42.fr>          +#+  +:+       +#+         ;
;                                                 +#+#+#+#+#+   +#+            ;
;    Created: 2020/06/22 16:08:59 by vvaucoul          #+#    #+#              ;
;    Updated: 2020/06/22 17:40:15 by vvaucoul         ###   ########.fr        ;
;                                                                              ;
; **************************************************************************** ;

SECTION .text
	global _ft_list_size

_ft_list_size:
				mov RCX, 0

loop:
				cmp RDI, 0
				je end
				mov RDI, [RDI + 8]
				inc RCX
				jmp loop

end:
				mov RAX, RCX
				ret

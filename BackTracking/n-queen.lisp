(setq flag 0)    ;; true면 1 false면 0
(setq l_r '())
(setq l_c '())

;; 퀸이 (row, col)에 위치할 수 있는지 검사하는 함수
;; 이미 놓인 퀸과 행, 열이 같지 않고 대각선으로도 만나면 안됨.
(defun check (row col size)
    (if (< 0 (length (member row l_r)))     ;; 행이 겹치는지 검사
        (return-from check 0)   ;;false
        (if (< 0 (length (member col l_c)))     ;; 열이 겹치는지 검사
            (return-from check 0)       ;;false
            (loop for k from 0 to (- size 1) do 
            ;; 대각선 검사 : 행끼리 뺀 값과 열끼리 뺀 값의 절대값들이 같으면 대각선.
                (setf r (nth k l_r))    
                (setf c (nth k l_c))
                (setf gp_r (abs (- r row)))
                (setf gp_c (abs (- c col)))
                (if (= gp_r gp_c) 
                    (return-from check 0)   ;;false
                )
            )
        )
    )
    (return-from check 1)   ;;모든 검사를 다 통과하면 check=1 반환 
)

(defun n-queen (row size flag)
    (loop for j from 1 to 4 do
        ; (print "----------")
        ; (print row)
        ; (print l_c)
        ; (print flag)
        (if (and (= row 4) (= (check row j size) 1)) 
        (progn (setf l_c (cons j l_c)) (print l_c)))
        (if (= (check row j size) 1)    ;;check를 1로 통과하면
            (progn
            (setf flag 1)           ;;flag=1
            (setf l_r (cons row l_r))       ;;행, 열 경로 리스트에 추가
            (setf l_c (cons j l_c))
            (n-queen (+ 1 row) (+ 1 size) flag))    ;;행+1, 경로 리스트 사이즈+1 해서 재귀
        )
        (setf flag 0)       ;; 해당 경로에서 못찾으면 flag=0
    )
    (if (= flag 0)      ;;flag==0이면 cdr로 경로 삭제
    (progn (setf l_r (cdr l_r)) (setf l_c (cdr l_c)); (print "execute")
    ; (print l_c)
    )
    )
)


(defun main ()
    (loop for k from 1 to 4 do  ;;1행 각 열을 반복문 돌리면서 경우의 수를 찾는다.
        (setq l_r '(1))
        (setq l_c '())
        (setq l_c (cons k l_c))
        (n-queen 2 1 0)
    )
)

 (main)

Implement Steps:  
1.讀檔  
2.建立動態L/U陣列 3.進行列運算:  
先計算和原矩陣第一列有關的LU 再繼續往下計算 每次都記錄原矩陣要乘以mup才能得pivot -mup即為L的下三角  
4.將L對角線設為0  
5.寫入output檔案

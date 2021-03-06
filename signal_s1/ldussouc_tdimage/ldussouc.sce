y = imread("M:\Documents\c++\tds\signal_s1\ldussouc_tdimage/koala.jpg")

y_mono = y(:,:, 1)

function ret = moyenneur(img)    
    ret = img
    for i = [2:1:299]
        for j = [2:1:299] 
            moyenne = img(i,j) /9 + img(i+1,j) /9 + img(i-1,j) /9 + img(i,j+1) /9 + img(i,j-1) /9 + img(i-1,j-1) /9 + img(i+1,j+1) /9 + img(i-1,j+1) /9 + img(i+1,j-1) /9 
            ret(i,j) = floor(moyenne)
        end
    end
endfunction

function ret = derivateurH(img)
    ret = img
    for i = [2:1:299]
        for j = [2:1:299] 
            ret(i,j) = abs(img(i-1,j) - img(i+1,j))
        end
    end
endfunction

function ret = median(img)
    ret = img
    for i = [2:1:299]
        for j = [2:1:299] 
            tableau = [img(i,j), img(i+1,j), img(i-1,j), img(i,j+1), img(i,j-1), img(i-1,j-1), img(i+1,j+1), img(i-1,j+1), img(i+1,j-1)]
            tableau_trie = gsort(tableau,'g','i')
            ret(i,j) = tableau_trie(5)
        end
    end
endfunction

y_mono_moyenneur = moyenneur(y_mono)
y_mono_derivateurH = derivateurH(y_mono)
y_mono_median = median(y_mono)

imshow(y_mono_median)


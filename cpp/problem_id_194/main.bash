# Read from the file file.txt and print its transposed content to stdout.

declare -A matrix

row=0
while read -r line; do
  col=0
  for word in $line; do
    matrix["$row,$col"]="$word"
    ((col += 1))
  done
  ((row += 1))
done <file.txt

for ((i = 0; i < col; i++)); do
  for ((j = 0; j < row; j++)); do
    ((j > 0)) && printf " "
    printf "%s" "${matrix["$j,$i"]}"
  done
  printf "\n"
done

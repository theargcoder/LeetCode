# Read from the file file.txt and output the tenth line to stdout.

n=0
while read -r line; do
  ((n == 9)) && echo "$line" && break
  ((n += 1))
done <file.txt

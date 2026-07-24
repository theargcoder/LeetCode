# Read from the file words.txt and output the word frequency list to stdout.

# wc words.txt -w

file=$(<words.txt)

declare -A words

for i in $file; do
  words[$i]=0
done

for i in $file; do
  ((words[$i]++))
done

output=$(
  for word in "${!words[@]}"; do
    echo "$word ${words[$word]}"
  done
)

sort -nr -k2 <<<"$output"

#!/bin/bash

for file in problem_*_id_*; do
    new_name=$(echo "$file" | sed -E 's/problem_[0-9]+_id_/problem_id_/')
    mv "$file" "$new_name"
done

echo "Renaming completed!"

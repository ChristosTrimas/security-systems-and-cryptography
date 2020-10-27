#!/bin/bash

git add .

echo 'Enter the commit summary:'
read summary

git commit -am "$summary"

echo 'Enter the name of the branch:'
read branch

git push $branch

# to read if git returns an error
read
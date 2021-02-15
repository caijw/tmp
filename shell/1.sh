#!/bin/bash
# 22
# if [ $# -ne 2 ]
# then
#        echo
#        echo Usage: test9.sh a b
#        echo
# else
#        total=$[ $1 + $2 ]
#        echo
#        echo The total is $total
#        echo
# fi
# params=$#

# echo The last parameter is $params
# echo The last parameter was ${!#}


# echo
# echo "Using the \$* method: $*"
# echo
# echo "Using the \$@ method: $@"


# echo
# count=1
# #
# for param in "$*"
# do
#    echo "\$* Parameter #$count = $param"
#    count=$[ $count + 1 ]
# done
# #
# echo
# count=1
# #
# for param in "$@"
# do
#    echo "\$@ Parameter #$count = $param"
#    count=$[ $count + 1 ]
# done
#sd


# echo
#     count=1
#     while [ -n "$1" ]
#     do
#        echo "Parameter #$count = $1"
#        count=$[ $count + 1 ]
#        shift
# done



# echo
# while [ -n "$1" ]
# do
#     case "$1" in
#         -a) echo "Found the -a option" ;;
#         -b) echo "Found the -b option";;
#         -c) echo "Found the -c option" ;;
#         --) shift
#             break ;;
#         *) echo "$1 is not an option";;
#     esac
#     shift 
# done
#     #
#     count=1
#     for param in $@
#     do
#        echo "Parameter #$count: $param"
#        count=$[ $count + 1 ]
#     done


echo
while [ -n "$1" ]
do
       case "$1" in
          -a) echo "Found the -a option";;
          -b) param="$2"
              echo "Found the -b option, with parameter value $param"
              shift ;;
          -c) echo "Found the -c option";;
          --) shift
              break ;;
           *) echo "$1 is not an option";;
        esac
        shift 
done
    #
    count=1
    for param in "$@"
    do
       echo "Parameter #$count: $param"
       count=$[ $count + 1 ]
    done


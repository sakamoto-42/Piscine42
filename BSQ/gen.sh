if [ "$*" == "" ];
then
	echo "No arguments provided"
fi

./srcs/gen.pl $1 $2 $3 > bsq.map

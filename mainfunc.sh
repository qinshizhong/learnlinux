valid_string() {
    while echo -e "$1 \c" 1>&2; do
        read name
        case $name in
            "") echo "Nothing entered" 1>&2; continue;;
            *) if [ 'expr "$name" : '.*'' -gt $2 ]; then
                   echo "Maximum $2 characters permitted" 1>&2
               else
                   break
               fi;;
        esac
    done
    echo $name
}

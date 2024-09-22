if [[ $EUID -ne 0 ]]; then 

    echo "This script requires root privileges. Please run with sudo."

    exit 1

fi


echo installing
apt install make gcc git
cd /tmp
git clone https://github.com/bit-sync/ops.git
cd ops/src
make install
echo done

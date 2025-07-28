sudo docker stop $(sudo docker ps -aq)
sudo docker rm $(sudo docker ps -aq)
sudo docker rmi $(sudo docker images -aq)
sudo docker volume rm $(sudo docker volume ls -q)
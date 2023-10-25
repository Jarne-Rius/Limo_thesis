FROM ros:noetic
# Sets frontend to noninteractive for Dockerfile
ENV DEBIAN_FRONTEND=noninteractive
# Makes sure shell is using bash
SHELL ["/bin/bash", "-c"]
# Sets the directory on container start-up to /root/
WORKDIR /home/Thesis
# ==================================================
### Initial updates/needed base packages
## rosdep
# Fix permissions for rosdep


WORKDIR /home
ADD /src/  /home/Thesis/src 
RUN sudo rosdep fix-permissions
RUN rosdep update
RUN sudo rosdep fix-permissions; 
RUN sudo echo 'debconf debconf/frontend select Noninteractive' | debconf-set-selections
    ##
    ## Essential packages
    # Update and Upgrade apt-get
RUN sudo apt-get update && sudo apt-get upgrade -y
    # Install dialog apt-utils package to remove warnings for using apt-get while building
RUN sudo apt-get install -y dialog apt-utils \
    # Install net-tools package
    net-tools \
    # Install iputils-ping package
    iputils-ping \
    # Install git package
    git \
    # Install nano package
    nano \
    # Install curl package
    curl \
    # Install wget package
    wget \
    # Install terminator package
    terminator \
    # Install software-properties-common package
    software-properties-common \
    ##
    ## Python3
    # Install python3-rosdep package
    python3-rosdep \
    # Install python3-rosinstall package
    python3-rosinstall \
    # Install python3-rosinstall-generator package
    python3-rosinstall-generator \
    # Install python3-wstool package
    python3-wstool \
    # Install build-essential package
    build-essential; \
    # Update apt-get
    sudo apt-get update;
    ##
    ## Catkin_ws
    # Source the setup.bash script
RUN  source /opt/ros/noetic/setup.bash; \
    # Add source command to ˜/.bashrc
    echo "source /opt/ros/noetic/setup.bash" >> ~/.bashrc;\
    # Source ˜/.bashrc
    source ~/.bashrc; \
    # Run the setup.bash script from the /opt/ros/noetic directory and change directory to ˜/catkin_ws. Build the packages in the catkin workspace using catkin_make
    . /opt/ros/noetic/setup.bash; cd ~/Thesis; \
    catkin_make; \
    # Add source command to ˜/.bashrc
    echo "source /home/Thesis/devel/setup.bash" >> ~/.bashrc; \
    # Source ˜/.bashrc
    source ~/.bashrc

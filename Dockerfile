# Use an official Ubuntu image as a parent image
FROM ubuntu:latest

# Install Clang and other dependencies
RUN apt-get update && apt-get install --no-install-recommends -y \
    clang \
    cmake \
    git \
    curl \
    wget \
    libcurl4-openssl-dev \
    libunwind-dev \
    libelf-dev \
    libdwarf-dev

# Copy the current directory contents into the container
COPY . /usr/src/app

# Set the working directory
WORKDIR /usr/src/app

# Compile the application
RUN clang++ -g -fno-omit-frame-pointer -mno-omit-leaf-frame-pointer -o myapp main.cpp

# Run the application
CMD ["./myapp"]

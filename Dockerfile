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
    libdwarf-dev \
    libc6-prof \
    libstdc++6-10-dbg && \
    rm -rf /var/lib/apt/lists/*

# Copy the current directory contents into the container
COPY . /usr/src/app

# Set the working directory
WORKDIR /usr/src/app

# Compile the application
RUN clang++ -g -fno-omit-frame-pointer -mno-omit-leaf-frame-pointer -o myapp main.cpp

# Run the application
CMD ["./myapp"]

FROM nidhamesselmani/my_docker_repo:cpp_jenkins_agent


COPY . /usr/cpp_app/
WORKDIR /usr/cpp_app/build

RUN cmake .. -G"Unix Makefiles"  -D CMAKE_CXX_COMPILER=g++ 

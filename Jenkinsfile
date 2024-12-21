pipeline {
    agent any
    stages {
        stage('Checkout') {
            steps {
                git 'https://github.com/OSoliman330/Hello_World_with_Jenkins.git'
            }
        }
        stage('Build') {
            steps {
                bat '''
                mkdir build
                cd build
                cmake -DCMAKE_BUILD_TYPE=Debug ..
                cmake --build . --config Debug
                '''
            }
        }
        stage('Run') {
            steps {
                bat '''
                cd build/bin
                HelloWorld.exe
                '''
            }
        }
    }
}
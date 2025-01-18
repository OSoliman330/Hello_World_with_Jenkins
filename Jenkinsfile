pipeline {
    agent any
    tools {
        'hudson.plugins.cmake.CmakeTool' 'CMake'
    }
    stages {
        stage('Checkout') {
            steps {
                git 'https://github.com/OSoliman330/Hello_World_with_Jenkins.git'
            }
        }
        stage('Configure') {
            steps {
                script {
                    if (isUnix()) {
                        sh '''
                        echo "Configuring the project..."
                        sudo cmake -S . -B build
                        sudo cmake --build build --target config
                        echo "Configuration completed successfully."
                        '''
                    } else {
                        bat '''
                        echo "Configuring the project..."
                        cmake -S . -B build
                        cmake --build build --target config
                        echo "Configuration completed successfully."
                        '''
                    }
                }
            }
        }
        stage('Build') {
            steps {
                script {
                    if (isUnix()) {
                        sh '''
                        echo "Building the project..."
                        sudo cmake --build build --target build
                        echo "Build completed successfully."
                        '''
                    } else {
                        bat '''
                        echo "Building the project..."
                        cmake --build build --target build
                        echo "Build completed successfully."
                        '''
                    }
                }
            }
        }
        stage('Test') {
            steps {
                script {
                    if (isUnix()) {
                        sh '''
                        echo "Testing the project..."
                        cd build/bin
                        ./TestMax
                        echo "Tests completed successfully."
                        '''
                    } else {
                        bat '''
                        echo "Testing the project..."
                        cd build\\bin
                        TestMax.exe
                        echo "Tests completed successfully."
                        '''
                    }
                }
            }
        }
        stage('Run') {
            steps {
                script {
                    if (isUnix()) {
                        sh '''
                        echo "Running the project..."
                        cd build/bin
                        ./HelloWorld
                        echo "Project run successfully."
                        '''
                    } else {
                        bat '''
                        echo "Running the project..."
                        cd build\\bin
                        HelloWorld.exe
                        echo "Project run successfully."
                        '''
                    }
                }
            }
        }
    }
}
